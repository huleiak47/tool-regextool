///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __RegexToolFrame__
#define __RegexToolFrame__

#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/treectrl.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class RegexToolFrame
///////////////////////////////////////////////////////////////////////////////
class RegexToolFrame : public wxFrame
{
private:

protected:
    wxPanel* m_panel;
    wxButton* m_btnStart;
    wxButton* m_btnClear;
    wxButton* m_btnPaste;
    wxButton* m_btnCopy;
    wxButton* m_btnCStyleCopy;

    wxStaticText* m_staticText1;
    wxChoice* m_choiceEncoding;
    wxTextCtrl* m_textPattern;
    wxButton* m_btnMatchClear;
    wxButton* m_btnMatchPaste;
    wxButton* m_btnMatchCopy;
    wxTextCtrl* m_textMatchText;
    wxTreeCtrl* m_treeMatchResult;

    // Virtual event handlers, overide them in your derived class
    virtual void OnButtonStartClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonClearClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonPasteClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonCopyClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonCStyleCopy(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonMatchClearClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonMatchPasteClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnButtonMatchCopyClick(wxCommandEvent& event)
    {
        event.Skip();
    }


public:

    RegexToolFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("正则表达式工具"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(600, 500), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
    ~RegexToolFrame();

};

#endif //__RegexToolFrame__
