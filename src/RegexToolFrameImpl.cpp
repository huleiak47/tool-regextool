#include "RegexToolFrameImpl.h"
#include <wx/wx.h>
#include <wx/clipbrd.h>
#include "regex_process.h"
#include <memory>
#include <stdexcept>
using namespace std;
#include <iconv.h>

RegexToolFrameImpl::RegexToolFrameImpl(wxWindow* parent, wxWindowID id /*= wxID_ANY*/, const wxString& title /*= wxT("正则表达式工具")*/, const wxPoint& pos /*= wxDefaultPosition*/, const wxSize& size /*= wxSize(681, 626)*/, long style /*= wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL*/)
    : RegexToolFrame(parent, id, title, pos, size, style), m_icon(wxICON(wxICON_AAA))
{
    m_textPattern->MoveBeforeInTabOrder(m_btnStart);
    this->SetIcon(m_icon);
}

RegexToolFrameImpl::~RegexToolFrameImpl(void)
{
}

static string UnicodeToString(const wstring& unicode, const string& stringCode)
{
    iconv_t env = iconv_open(stringCode.c_str(), "WCHAR_T");
    if (env == (iconv_t) - 1)
    {
        throw logic_error(string("iconv_open failed from ") + stringCode + " to WCHAR_T.");
    }
    size_t inleft = unicode.length() * sizeof(wchar_t);
    size_t outleft = unicode.length() * 4;
    auto_ptr<char> outbuf(new char[outleft]);
    char* outb = outbuf.get();
    char* inbuf = (char*)unicode.c_str();
    size_t ret = iconv(env, (char**)&inbuf, &inleft, &outb, &outleft);
    iconv_close(env);
    if (ret == (size_t) - 1)
    {
        throw logic_error(string("iconv failed from ") + stringCode + " to WCHAR_T.");
    }
    return string(outbuf.get(), unicode.length() * 4 - outleft);
}


static wstring StringToUnicode(const string& str, const string& stringCode)
{
    iconv_t env = iconv_open("WCHAR_T", stringCode.c_str());
    if (env == (iconv_t) - 1)
    {
        throw logic_error(string("iconv_open failed from WCHAR_T to ") + stringCode + ".");
    }
    size_t inleft = str.length();
    size_t outleft = str.length() * sizeof(wchar_t);
    auto_ptr<wchar_t> outbuf(new wchar_t[inleft]);
    wchar_t* outb = outbuf.get();
    char* inbuf = (char*)str.c_str();

    size_t ret = iconv(env, (char**)&inbuf, &inleft, (char**)&outb, &outleft);
    iconv_close(env);
    if (ret == (size_t) - 1)
    {
        throw logic_error(string("iconv failed from WCHAR_T to ") + stringCode + ".");
    }
    return wstring(outbuf.get(), (str.length() * sizeof(wchar_t) - outleft) / sizeof(wchar_t));
}

void RegexToolFrameImpl::OnButtonStartClick(wxCommandEvent& event)
{
    wxString pattern = m_textPattern->GetValue();
    wxString value = m_textMatchText->GetValue();

    //int encIndex = m_choiceEncoding->GetSelection();
    string encode = UnicodeToString(m_choiceEncoding->GetStringSelection().ToStdWstring(), "ASCII");

    if (encode == "WCHAR_T") // UNICODE
    {
        vector<vector<wstring> > result;
        try
        {
            begin_match(wstring(pattern.c_str()), wstring(value.c_str()), result);
        }
        catch (regex_error& e)
        {
            wxMessageBox(StringToUnicode(e.what(), "ASCII"), wxT("Error"), wxOK | wxICON_ERROR);
            return;
        }
        this->AddResults(result);
    }
    else
    {
        vector<vector<string> > result;
        string spattern;
        string svalue;
        try
        {
            spattern = UnicodeToString(pattern.ToStdWstring(), encode);
            svalue = UnicodeToString(value.ToStdWstring(), encode);
        }
        catch (logic_error& e)
        {
            wxMessageBox(StringToUnicode(e.what(), "ASCII").c_str(), wxT("Error"), wxOK | wxICON_ERROR);
            return;
        }
        try
        {
            begin_match(spattern, svalue, result);
        }
        catch (regex_error& e)
        {
            wxMessageBox(StringToUnicode(e.what(), "ASCII").c_str(), wxT("Error"), wxOK | wxICON_ERROR);
            return;
        }
        this->AddResults(result, encode);
    }
}

void RegexToolFrameImpl::AddResults(vector<vector<wstring> >& result)
{
    m_treeMatchResult->DeleteAllItems();
    wxTreeItemId root = m_treeMatchResult->AddRoot(wxT("Result:"));
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i].size() == 0)
        {
            continue;
        }
        wxTreeItemId child = m_treeMatchResult->AppendItem(root, result[i][0].c_str());
        for (size_t j = 1; j < result[i].size(); ++j)
        {
            m_treeMatchResult->AppendItem(child, result[i][j].c_str());
        }
    }
    m_treeMatchResult->Expand(root);
}

void RegexToolFrameImpl::AddResults(vector<vector<string> >& result, const string& stringCode)
{
    m_treeMatchResult->DeleteAllItems();
    wxTreeItemId root = m_treeMatchResult->AddRoot(wxT("Result:"));
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i].size() == 0)
        {
            continue;
        }
        wxTreeItemId child = m_treeMatchResult->AppendItem(root, StringToUnicode(result[i][0], stringCode).c_str());
        for (size_t j = 1; j < result[i].size(); ++j)
        {
            m_treeMatchResult->AppendItem(child, StringToUnicode(result[i][j], stringCode).c_str());
        }
    }
    m_treeMatchResult->Expand(root);
}

void RegexToolFrameImpl::OnButtonClearClick(wxCommandEvent& event)
{
    m_textPattern->SetValue(wxT(""));
}

void RegexToolFrameImpl::OnButtonPasteClick(wxCommandEvent& event)
{
    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);
            m_textPattern->SetValue(data.GetText());
        }
        wxTheClipboard->Close();
    }
}

void RegexToolFrameImpl::OnButtonCopyClick(wxCommandEvent& event)
{
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(m_textPattern->GetValue()));
        wxTheClipboard->Close();
    }
}

void RegexToolFrameImpl::OnButtonMatchClearClick(wxCommandEvent& event)
{
    m_textMatchText->SetValue(wxT(""));
}

void RegexToolFrameImpl::OnButtonMatchPasteClick(wxCommandEvent& event)
{
    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);
            m_textMatchText->SetValue(data.GetText());
        }
        wxTheClipboard->Close();
    }
}

void RegexToolFrameImpl::OnButtonMatchCopyClick(wxCommandEvent& event)
{
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(m_textMatchText->GetValue()));
        wxTheClipboard->Close();
    }
}

void RegexToolFrameImpl::OnButtonCStyleCopy(wxCommandEvent& event)
{
    if (wxTheClipboard->Open())
    {
        wxString pattern = m_textPattern->GetValue();
        pattern.Replace(wxT("\\"), wxT("\\\\"));
        wxTheClipboard->SetData(new wxTextDataObject(pattern));
        wxTheClipboard->Close();
    }
}

