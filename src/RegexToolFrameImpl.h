#ifndef __REGEXTOOLFRAMEIMPL_H__
#define __REGEXTOOLFRAMEIMPL_H__

#include <wx/wx.h>
#include "RegexToolFrame.h"
#include <vector>
using namespace std;

class RegexToolFrameImpl : public RegexToolFrame
{
public:
    RegexToolFrameImpl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("正则表达式工具"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(681, 626), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
    virtual ~RegexToolFrameImpl(void);
    virtual void OnButtonStartClick(wxCommandEvent& event);
    virtual void OnButtonClearClick(wxCommandEvent& event);
    virtual void OnButtonPasteClick(wxCommandEvent& event);
    virtual void OnButtonCopyClick(wxCommandEvent& event);
    virtual void OnButtonCStyleCopy(wxCommandEvent& event);
    virtual void OnButtonMatchClearClick(wxCommandEvent& event);
    virtual void OnButtonMatchPasteClick(wxCommandEvent& event);
    virtual void OnButtonMatchCopyClick(wxCommandEvent& event);

private:
    void AddResults(vector<vector<wstring> >& result);
    void AddResults(vector<vector<string> >& result, const string& stringCode);
    wxIcon m_icon;
};

#endif //__REGEXTOOLFRAMEIMPL_H__
