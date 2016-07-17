/******************************************************************************
 * $Id: ocpndebuggergui_impl.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
 *
 * Project:  OpenCPN
 * Purpose:  OpenCPNDebugger Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Pavel Kalian   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#include "ocpndebuggergui_impl.h"

enum { MESSAGE_ID, COUNT, TIME, RATE, TOTAL_DATA };

class Message
{
public:
    Message(wxString body) : time(wxDateTime::Now()), total_data(body.Length()), message_body(body)
        {
        }

    wxDateTime time;
    long total_data;
    wxString message_body;
};

OpenCPNDebuggerDlgImpl::OpenCPNDebuggerDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : OpenCPNDebuggerDlg( parent, id, title, pos, size, style )
{
    m_lMessages->InsertColumn(MESSAGE_ID, _("Message ID"));
    m_lMessages->InsertColumn(COUNT, _("Count"));
    m_lMessages->InsertColumn(TIME, _("Time"));
    m_lMessages->InsertColumn(RATE, _("Rate"));
    m_lMessages->InsertColumn(TOTAL_DATA, _("Total Data"));
}


#define foreach(LIST, TYPE, VAR) \
    TYPE VAR; \
    for(std::list<TYPE>::iterator LIST##iterator = LIST.begin(); \
        LIST##iterator==LIST.end() ? 0 : (VAR = *LIST##iterator,1); LIST##iterator++)

void OpenCPNDebuggerDlgImpl::SetGPSMessage(wxString &msg)
{
    if (m_tbPause->GetValue()) {
        foreach(m_paused_gps_messages, wxString, str)
            m_tcGPS->AppendText(str);
        m_paused_gps_messages.clear();
        m_tcGPS->AppendText(msg);
    } else
        m_paused_gps_messages.push_back(msg);
}

void OpenCPNDebuggerDlgImpl::SetNMEAEvent(wxString &msg)
{
    if (m_tbPause->GetValue())
        m_paused_nmea_events.push_back(msg);
    else {
        foreach(m_paused_nmea_events, wxString, str)
            m_tcEvents->AppendText(str);
        m_paused_nmea_events.clear();
        m_tcEvents->AppendText(msg);
    }
}

void OpenCPNDebuggerDlgImpl::SetAISMessage(wxString &msg)
{
    if (m_tbPause->GetValue())
        m_paused_ais_messages.push_back(msg);
    else {
        foreach(m_paused_ais_messages, wxString, str)
            m_tcAIS->AppendText(str);
        m_paused_ais_messages.clear();
        m_tcAIS->AppendText(msg);
    }
}

typedef std::pair<wxString, wxString> MsgStr;
void OpenCPNDebuggerDlgImpl::SetPluginMessage(wxString &id, wxString &msg)
{
    if (m_tbPause->GetValue())
        m_paused_messages.push_back(MsgStr(id, msg));
    else {
        foreach(m_paused_messages, MsgStr, pair)
            SetPluginMessageInternal(pair.first, pair.second);
        m_paused_messages.clear();
        SetPluginMessageInternal(id, msg);
    }
}

static wxString StringCurrentTime()
{
    return wxDateTime::Now().FormatTime();
}


void OpenCPNDebuggerDlgImpl::SetPluginMessageInternal(wxString &message_id, wxString &message_body)
{
    // eventually parse json into tree?  Allow editing messages and resending?
//    wxJSONReader r;
//    wxJSONValue v;
//    r.Parse(message_body, &v);

    // determine selected message by id to update the body if needed
    long selected_index = m_lMessages->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    // look for existing id in list, and update
    for(int i=0; i<m_lMessages->GetItemCount(); i++)
        if(message_id == m_lMessages->GetItemText(i, MESSAGE_ID)) {
            // increment count
            long count = 0;
            m_lMessages->GetItemText(i, COUNT).ToLong(&count);
            count++;
            m_lMessages->SetItem(i, COUNT, wxString::Format(_T("%ld"), count));

            Message *msg =
                reinterpret_cast<Message*>(wxUIntToPtr(m_lMessages->GetItemData(i)));
            wxTimeSpan period = wxDateTime::Now() - msg->time;

            m_lMessages->SetItem(i, RATE, wxString::Format(_T("%.1fhz"), count*1000.0/period.GetMilliseconds().ToLong()));

            msg->total_data += message_body.Length();
            wxString total_data_str;
            if(msg->total_data < 1024)
                total_data_str = wxString::Format(_T("%ld b"), msg->total_data);
            else if(msg->total_data < 1024*1024)
                total_data_str = wxString::Format(_T("%.1f kb"), msg->total_data/1024.0);
            else if(msg->total_data < 1024*1024*1024)
                total_data_str = wxString::Format(_T("%.1f mb"), msg->total_data/1024.0/1024.0);
            else
                total_data_str = wxString::Format(_T("%.1f gb"), msg->total_data/1024.0/1024.0/1024.0);
            
            m_lMessages->SetItem(i, TOTAL_DATA, total_data_str);
            msg->message_body = message_body; // update message

            if(i == selected_index)
                m_stMessage->SetLabel(message_body);
            return;
        }

    // not in list, add it
    wxListItem item;
    selected_index = m_lMessages->InsertItem(m_lMessages->GetItemCount(), item);
    m_lMessages->SetItem(selected_index, MESSAGE_ID, message_id);
    m_lMessages->SetColumnWidth(MESSAGE_ID, wxLIST_AUTOSIZE);
    m_lMessages->SetItem(selected_index, COUNT, _T("1"));
    m_lMessages->SetItem(selected_index, TIME, StringCurrentTime());
    m_lMessages->SetItem(selected_index, RATE, wxEmptyString);
    m_lMessages->SetItem(selected_index, TOTAL_DATA, wxString::Format(_T("%ld b"), message_body.Length()));

    m_lMessages->SetItemPtrData(selected_index, wxPtrToUInt(new Message(message_body)));
}

void OpenCPNDebuggerDlgImpl::OnMessageSelected( wxListEvent& event )
{
    long index = m_lMessages->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    if(index == -1)
        m_stMessage->SetLabel(_("No Message Selected"));
    else {
        wxString message_body =
            reinterpret_cast<Message*>(wxUIntToPtr(m_lMessages->GetItemData(index)))->message_body;
        m_stMessage->SetLabel(message_body);
        m_stMessage->Fit();

        // hack
        wxSize s = m_scrolledWindow1->GetSize();
        m_scrolledWindow1->SetSize(wxSize(100, 100));
        m_scrolledWindow1->SetSize(s);
    }
}

void OpenCPNDebuggerDlgImpl::OnClear( wxCommandEvent& event )
{
    m_tcGPS->Clear();
    m_tcEvents->Clear();
    m_tcAIS->Clear();
    m_lMessages->DeleteAllItems();
}
