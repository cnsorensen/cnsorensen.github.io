#include <string>
#include "season.h"

FILE* DEGFILE;

int COUNT = 0;

Season seasons[9];

void Write(const char* str)
{
    fprintf(DEGFILE, "%s", str);
}

void Write(char c)
{
    fprintf(DEGFILE, "%c", c);
}

void Write(int i)
{
    fprintf(DEGFILE, "%d", i);
}

void WriteLine(const char* str)
{
    // TODO: address season number being in the double digits
    Write("<span class=\"season");
    Write(str[0]);
    Write("\">");

    // Only write numbers if it's for the episodes
    if(COUNT > 0)
    {
      Write(COUNT);
      Write(". ");
    }

    // TODO: find the index of the comma instead of hardcoding a value
    int i = 2;
    while(str[i] != '\0')
    {
      Write(str[i]);
      i++;
    }

    Write("</span><br>\n");
}

void WriteEpisodes()
{
    FILE* epListFile;
    COUNT = 1;

    epListFile = fopen("episodelist.txt", "r");
    if(epListFile == NULL)
    {
      printf("Error opening file.\n");
      return;
    }

    char line[256];

    while(fscanf(epListFile, "%[^\n]\n", line) != EOF)
    {
      WriteLine(line);
      COUNT++;
    }

    fclose(epListFile);
}

void WriteSeasons()
{
    WriteLine("1,Season 1");
    WriteLine("2,Season 2");
    WriteLine("3,Season 3");
    WriteLine("4,Season 4");
    WriteLine("5,Season 5");
    WriteLine("6,Season 6");
    WriteLine("7,Season 7");
    WriteLine("8,Season 8");
    WriteLine("9,Season 9");
}

void WriteStyle()
{
    Write("<style>\n");

    // Blinking animation for current episode
    Write(".blink {\n");
    Write("animation: blink-animation 1s steps(5, start) infinite;\n");
    Write("-webkit-animation: blink-animation 1s steps(5,start) infinite;\n}\n");
    Write("@keyframes blink-animation {\nto {\nvisibility: hidden;\n}\n}\n");
    Write("@-webkit-keyframes blink-animation {\nto {\nvisibility: hidden;\n}\n}\n");

    // write the style for each season
    for(int i = 0; i < 9; i++)
    {
        seasons[i].WriteStyle(DEGFILE);
    }

    Write("</style\n");
}

void WriteHeader()
{
    Write("<head>\n");

    Write("<meta name=\"GENERATOR\" content=\"Vim\">\n");
    Write("<title>DEGRASSI RANKING EH</title>\n");
    Write("<link rel=\"icon\" href=\"images/jtyorke.ico\">\n");

    WriteStyle();

    Write("</head>\n");
}

void WriteBody()
{
    Write("<body bgcolor=\"FFF6F0\" background=\"images/paige.gif\" text= \"#C41502\">\n");
    Write("<basefont face=\"Times,Courier\">\n");

    // Header DEGRASSI RANKING EH! on top of page
    Write("<table align=\"CENTER\" width=\"80%%\">\n");
    Write("<tbody>\n<tr><td>\n<font size=\"5\">\n<h1 align=\"CENTER\">\n");
    Write("<blink>\n<marquee behavior=\"ALTERNATE\">\nDEGRASSI RANKING EH!\n");
    Write("</marquee>\n</blink>\n</h1>\n</font>\n</td></tr>\n</tbody>\n</table>\n");

    // White box with episode list
    Write("<table align=\"CENTER\" width=\"60%%\">\n<tbody>\n<tr><td>\n");
    Write("<table align=\"CENTER\" width=\"100%%\" bgcolor=\"#FFFFFF\">\n<tbody>\n<tr><td colspan=\"3\">\n<font size=\"4\">\n");

    // Intro to ranking
    Write("<p align=\"CENTER\">\nHeey! I've been rewatching all the episodes of\n <font face=\"Comic Sans MS\" size=\"5\" color=\"#000000\">\n");
    Write("<a href=\"https://en.wikipedia.com/wiki/Degrassi:_The_Next_Generation\">Degrassi: The Next Generation</a>\n</font>\nand ranking them. I am currently on episode:\n");

    // Currently on episode
    // TODO: create a variable for the current episode instead of hardcoding it here
    Write("</p>\n<p align=\"CENTER\"><span class=\"blink\">\n<span class=\"season9\">\nSeason  Episode 7: Beat It Part 1\n");

    // Color coded seasons
    Write("</span></span></p>\n<p align=\"CENTER\"><font face=\"Comic Sans MS\">I've color coded each episode by their season:\n<br></font>\n");
    WriteSeasons();

    // Episode list
    Write("</p><hr>\n<p align=\"CENTER\">\n");
    WriteEpisodes();

    // End of Text in white box
    Write("</p></font></td></tr> \n</tbody></table>\n");
    // End of White box
    Write("</td></tr></tbody></table>\n");

    Write("<table align=\"CENTER\" width=\"60%%\">");
    Write("<tbody><tr><td><p align=\"CENTER\">");
    Write("<img src=\"http://www.netanimations.net/fire-under-construction-animation.gif\" alt=\"UNDER CONSTRUCTION\">");
    Write("</p></td></tr></tbody></table>");

    Write("</body>\n");
}

void WriteFooter()
{
    Write("<footer>\n");

    Write("<table align=\"CENTER\" width=\"100%%\"><tbody><tr><td>");

    Write("<table align=\"LEFT\" width=\"100%%\" bgcolor=\"#941001\">");
    Write("<tbody><tr><td colspan=\"3\"><font size=\"5\">");
    Write("<p align=\"CENTER\"><a href=\"index.html\">~~! Return to homepage !~~</a></p>");
    Write("</font><hr><font color=\"#FFFFFF\"><p>Author:christine<br>Copyright 20223</p>");
    Write("</font></td></tr></tbody></table></td></tr></tbody></table>");

    Write("</footer>\n");
}

void WriteHtml()
{
    // Write to the HTML file
    Write("<!DOCTYPE html>\n");
    Write("<html>\n");

    WriteHeader();
    WriteBody();
    WriteFooter();

    Write("</html>\n");
}

int main(int argc, char* argv[])
{
    // Open the HTML file
    DEGFILE = fopen("../degrassi.html", "w");
    if(DEGFILE == NULL)
    {
      printf("Error opening file.\n");
      return 0;
    }

    // create seasons and add to array
    seasons[0] = Season((char*)"1", (char*)"darkblue", (char*)"courier", (char*)"120");
    seasons[1] = Season((char*)"2", (char*)"green", (char*)"comic sans ms", (char*)"100");
    seasons[2] = Season((char*)"3", (char*)"red", (char*)"trebuchet", (char*)"100");
    seasons[3] = Season((char*)"4", (char*)"black", (char*)"garamond", (char*)"110");
    seasons[4] = Season((char*)"5", (char*)"purple", (char*)"brust script mt", (char*)"120");
    seasons[5] = Season((char*)"6", (char*)"brown", (char*)"courier", (char*)"110");
    seasons[6] = Season((char*)"7", (char*)"gold", (char*)"comic sans ms", (char*)"100");
    seasons[7] = Season((char*)"8", (char*)"dodgerblue", (char*)"garmond", (char*)"110");
    seasons[8] = Season((char*)"9", (char*)"red", (char*)"courier", (char*)"90");

    WriteHtml();

    // Close the HTML file
    fclose(DEGFILE);

    return 1;
}
