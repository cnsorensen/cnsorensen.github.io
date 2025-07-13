// season.h
#ifndef SEASON_H
#define SEASON_H

#include <stdio.h>

class Season
{
public:
    Season() {}
    // TODO add constructor for default font size 100%
    Season(char* sn, char* fc, char* ff, char* fs)
    {
        m_seasonNum = sn;
        m_fontColor = fc;
        m_fontFamily = ff;
        m_fontSize = fs;
    }

    ~Season() {}

    void WriteStyle(FILE* file);

private:
    char* m_seasonNum;
    char* m_fontColor;
    char* m_fontFamily;
    char* m_fontSize;
};


#endif // SEASON_H


