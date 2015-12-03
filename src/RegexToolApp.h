#ifndef __REGEXTOOLAPP_H__
#define __REGEXTOOLAPP_H__


#include <wx/wx.h>

class RegexToolApp : public wxApp
{
public:
    RegexToolApp(void);
    virtual ~RegexToolApp(void);

    virtual bool OnInit();
};

DECLARE_APP(RegexToolApp)

#endif //__REGEXTOOLAPP_H__
