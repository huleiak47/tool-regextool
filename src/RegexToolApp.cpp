#include "RegexToolApp.h"
#include "RegexToolFrameImpl.h"

IMPLEMENT_APP(RegexToolApp)
RegexToolApp::RegexToolApp(void)
{
}

RegexToolApp::~RegexToolApp(void)
{
}

bool RegexToolApp::OnInit()
{
    wxFrame * pFrame = new RegexToolFrameImpl(NULL);
    SetTopWindow(pFrame);
    pFrame->Show();
    return true;
}
