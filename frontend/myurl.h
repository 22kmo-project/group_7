#ifndef MYURL_H
#define MYURL_H

#include <QString>


class MyURL
{
public:
    MyURL();
    static QString getBaseUrl();

private:
    static QString base_url;
};

#endif // MYURL_H
