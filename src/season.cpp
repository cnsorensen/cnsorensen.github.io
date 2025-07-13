// season.cpp
#include "season.h"

void Season::WriteStyle(FILE* file)
{
    fprintf(file, "%s", ".season");
    fprintf(file, "%s", m_seasonNum);
    fprintf(file, "%s", " {color: ");
    fprintf(file, "%s", m_fontColor);
    fprintf(file, "%s", "; font-family: ");
    fprintf(file, "%s", m_fontFamily);
    fprintf(file, "%s", "; font-size: ");
    fprintf(file, "%s", m_fontSize);
    fprintf(file, "%s", "%;}\n");
}


