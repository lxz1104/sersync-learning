/* 
 * File:   CdnRefresh.h
 * Author: 周洋 JohnTech
 *
 * Created on 2010年1月19日, 下午3:29
 */
#ifndef _CDNREFRESH_H
#define	_CDNREFRESH_H
#include "Inotify.h"
#include "Interface.h"
#include <fstream>

class CdnRefreshInterface : public Interface {
public:
    /** 域名 */
    std::string m_domainName;
    /** 用户名 */
    std::string m_username;
    /** 密码 */
    std::string m_passwd;
    /** 是否使用正则表达式匹配 */
    std::string m_regexFlag; //if == 'false' will ignore the regex match;
    /** */
    std::string m_urlBase;
    /** */
    std::string m_urlRegex;
    /** */
    std::ofstream m_fout;
public:
    /**
     * 默认构造函数
     */
    CdnRefreshInterface();

    /**
     * 解析XML配置文件
     * @param xml 配置文件路径
     */
    void XmlParse(std::string xml = "confxml.xml") override;

    /**
     *
     * @param e
     * @return
     */
    int Execute(Event e) override;
protected:
    std::string PackagePath(const Event& e);
    void ErrorLog(std::string temp,const std::string& fullPath);
};

#endif	/* _CDNREFRESH_H */

