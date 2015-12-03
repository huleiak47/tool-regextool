///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "RegexToolFrame.h"

///////////////////////////////////////////////////////////////////////////

RegexToolFrame::RegexToolFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxSize(600, 500), wxDefaultSize);

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    m_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer* sbSizer1;
    sbSizer1 = new wxStaticBoxSizer(new wxStaticBox(m_panel, wxID_ANY, wxT("正则表达式")), wxVERTICAL);

    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    m_btnStart = new wxButton(m_panel, wxID_ANY, wxT("开始"), wxDefaultPosition, wxDefaultSize, 0);
    m_btnStart->SetDefault();
    bSizer2->Add(m_btnStart, 0, wxALL, 5);

    m_btnClear = new wxButton(m_panel, wxID_ANY, wxT("清空"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_btnClear, 0, wxALL, 5);

    m_btnPaste = new wxButton(m_panel, wxID_ANY, wxT("粘贴"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_btnPaste, 0, wxALL, 5);

    m_btnCopy = new wxButton(m_panel, wxID_ANY, wxT("复制"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_btnCopy, 0, wxALL, 5);

    m_btnCStyleCopy = new wxButton(m_panel, wxID_ANY, wxT("复制C风格"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_btnCStyleCopy, 0, wxALL, 5);


    bSizer2->Add(0, 0, 1, wxEXPAND, 5);

    m_staticText1 = new wxStaticText(m_panel, wxID_ANY, wxT("编码："), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->Wrap(-1);
    bSizer2->Add(m_staticText1, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    wxString m_choiceEncodingChoices[] = { wxT("WCHAR_T"), wxT("ASCII"), wxT("GBK"), wxT("UTF-8") };

    int m_choiceEncodingNChoices = sizeof(m_choiceEncodingChoices) / sizeof(wxString);
    m_choiceEncoding = new wxChoice(m_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceEncodingNChoices, m_choiceEncodingChoices, 0);
    m_choiceEncoding->SetSelection(0);
    bSizer2->Add(m_choiceEncoding, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    sbSizer1->Add(bSizer2, 0, wxEXPAND, 5);

    m_textPattern = new wxTextCtrl(m_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    sbSizer1->Add(m_textPattern, 0, wxALL | wxEXPAND, 5);

    bSizer4->Add(sbSizer1, 0, wxALL | wxEXPAND, 5);

    wxStaticBoxSizer* sbSizer2;
    sbSizer2 = new wxStaticBoxSizer(new wxStaticBox(m_panel, wxID_ANY, wxT("匹配文本")), wxVERTICAL);

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_btnMatchClear = new wxButton(m_panel, wxID_ANY, wxT("清空"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_btnMatchClear, 0, wxALL, 5);

    m_btnMatchPaste = new wxButton(m_panel, wxID_ANY, wxT("粘贴"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_btnMatchPaste, 0, wxALL, 5);

    m_btnMatchCopy = new wxButton(m_panel, wxID_ANY, wxT("复制"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_btnMatchCopy, 0, wxALL, 5);

    sbSizer2->Add(bSizer3, 0, wxEXPAND, 5);

    m_textMatchText = new wxTextCtrl(m_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    sbSizer2->Add(m_textMatchText, 1, wxALL | wxEXPAND, 5);
    m_textMatchText->SetMinSize(wxSize(-1, 200));

    bSizer4->Add(sbSizer2, 1, wxALL | wxEXPAND, 5);

    wxStaticBoxSizer* sbSizer3;
    sbSizer3 = new wxStaticBoxSizer(new wxStaticBox(m_panel, wxID_ANY, wxT("匹配结果")), wxVERTICAL);

    m_treeMatchResult = new wxTreeCtrl(m_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE);
    sbSizer3->Add(m_treeMatchResult, 1, wxALL | wxEXPAND, 5);
    m_treeMatchResult->SetMinSize(wxSize(-1, 200));

    bSizer4->Add(sbSizer3, 1, wxALL | wxEXPAND, 5);

    m_panel->SetSizer(bSizer4);
    m_panel->Layout();
    bSizer4->Fit(m_panel);
    bSizer1->Add(m_panel, 1, wxEXPAND, 5);

    this->SetSizerAndFit(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    m_btnStart->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonStartClick), NULL, this);
    m_btnClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonClearClick), NULL, this);
    m_btnPaste->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonPasteClick), NULL, this);
    m_btnCopy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonCopyClick), NULL, this);
    m_btnCStyleCopy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonCStyleCopy), NULL, this);
    m_btnMatchClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonMatchClearClick), NULL, this);
    m_btnMatchPaste->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonMatchPasteClick), NULL, this);
    m_btnMatchCopy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonMatchCopyClick), NULL, this);
}

RegexToolFrame::~RegexToolFrame()
{
    // Disconnect Events
    m_btnStart->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonStartClick), NULL, this);
    m_btnClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonClearClick), NULL, this);
    m_btnPaste->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonPasteClick), NULL, this);
    m_btnCopy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonCopyClick), NULL, this);
    m_btnCStyleCopy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonCStyleCopy), NULL, this);
    m_btnMatchClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonMatchClearClick), NULL, this);
    m_btnMatchPaste->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonMatchPasteClick), NULL, this);
    m_btnMatchCopy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RegexToolFrame::OnButtonMatchCopyClick), NULL, this);

}
