/**
 * @file regex_process.h
 * @brief
 * @author hulei
 * @version 1.0
 * @date 2011-06-25
 */

#ifndef __REGEX_PROCESS_H__
#define __REGEX_PROCESS_H__

#include <string>
#include <vector>
using namespace std;
#include <boost/xpressive/xpressive.hpp>
using namespace boost::xpressive;
/**
 * @brief
 *
 * @param pattern
 * @param value
 *
 * @return true = begin false = and thread is already begin
 */
template <typename T>
void begin_match(const T& pattern, const T& value, vector<vector<T> >& result)
{
    result.clear();
    basic_regex<typename T::const_iterator> re = basic_regex<typename T::const_iterator>::compile(pattern.begin(), pattern.end());
    regex_iterator<typename T::const_iterator> pos(value.begin(), value.end(), re);
    regex_iterator<typename T::const_iterator> end;
    while (pos != end)
    {
        vector < T > vecstr;
        for (size_t i = 0; i < (*pos).size(); i++)
        {
            vecstr.push_back((*pos)[i]);
        }
        result.push_back(vecstr);
        ++pos;
    }
}

#endif
