#include <stdio.h>
#include <stdlib.h>
#include <string>

FILE* DEGFILE;

void WRITE(const char* str)
{
  fprintf(DEGFILE, str);
}

void WRITE(char c)
{
  fprintf(DEGFILE, "%c", c);
}

void WRITELINE(const char* str)
{
  //<span class="season1">Season 1</span></a><br>
  WRITE("<span class=\"season");
  WRITE(str[0]);
  WRITE("\">");

  int i = 2;
  while(str[i] != '\0')
  {
    WRITE(str[i]);
    i++;
  }

  WRITE("</span><br>\n");
}

void WriteEpisodes()
{
  FILE* epListFile;

  epListFile = fopen("episodelist.txt", "r");
  if(epListFile == NULL)
  {
    printf("Error opening file.\n");
    return;
  }

  char line[256];

  while(fscanf(epListFile, "%[^\n]\n", line) != EOF)
  {
    WRITELINE(line);
  }

  fclose(epListFile);
}

void WriteSeasons()
{
  WRITELINE("1,Season 1");
  WRITELINE("2,Season 2");
  WRITELINE("3,Season 3");
  WRITELINE("4,Season 4");
  WRITELINE("5,Season 5");
  WRITELINE("6,Season 6");
  WRITELINE("7,Season 7");
  WRITELINE("8,Season 8");
}

void WriteStyle()
{
  WRITE("<style>\n");

  // Blinking animation for current episode
  WRITE(".blink {\n");
  WRITE("animation: blink-animation 1s steps(5, start) infinite;\n");
  WRITE("-webkit-animation: blink-animation 1s steps(5,start) infinite;\n}\n");
  WRITE("@keyframes blink-animation {\nto {\nvisibility: hidden;\n}\n}\n");
  WRITE("@-webkit-keyframes blink-animation {\nto {\nvisibility: hidden;\n}\n}\n");

  // The different styles for each season
  WRITE(".season1 {color: darkblue;font-family: courier;font-size: 120%%;}\n");
  WRITE(".season2 {color: green;font-family: comic sans ms;}\n");
  WRITE(".season3 {color: red;font-family: trebuchet ms;}\n");
  WRITE(".season4 {color: black;font-family: garamond;font-size: 110%%;}\n");
  WRITE(".season5 {color: purple;font-family: brush script mt;font-size: 120%%;}\n");
  WRITE(".season6 {color: brown;font-family: courier;font-size: 110%%;}\n");
  WRITE(".season7 {color: gold;font-family: comic sans ms;}\n");
  WRITE(".season8 {color: dodgerblue;font-family: garmond;}\n");
  WRITE("</style\n");
}

void WriteHeader()
{
  WRITE("<head>\n");

  WRITE("<meta name=\"GENERATOR\" content=\"Vim\">\n");
  WRITE("<title>DEGRASSI RANKING EH</title>\n");
  WRITE("<link rel=\"icon\" href=\"images/jtyorke.ico\">\n");

  WriteStyle();

  WRITE("</head>\n");
}

void WriteBody()
{
  WRITE("<body bgcolor=\"FFF6F0\" background=\"images/paige.gif\" text= \"#C41502\">\n");
  WRITE("<basefont face=\"Times,Courier\">\n");

  // Header DEGRASSI RANKING EH! on top of page
  WRITE("<table align=\"CENTER\" width=\"80%%\">\n");
  WRITE("<tbody>\n<tr><td>\n<font size=\"5\">\n<h1 align=\"CENTER\">\n");
  WRITE("<blink>\n<marquee behavior=\"ALTERNATE\">\nDEGRASSI RANKING EH!\n");
  WRITE("</marquee>\n</blink>\n</h1>\n</font>\n</td></tr>\n</tbody>\n</table>\n");

  // White box with episode list
  WRITE("<table align=\"CENTER\" width=\"60%%\">\n<tbody>\n<tr><td>\n");
  WRITE("<table align=\"CENTER\" width=\"100%%\" bgcolor=\"#FFFFFF\">\n<tbody>\n<tr><td colspan=\"3\">\n<font size=\"4\">\n");

  // Intro to ranking
  WRITE("<p align=\"CENTER\">\nHeey! I've been rewatching all the episodes of\n <font face=\"Comic Sans MS\" size=\"5\" color=\"#000000\">\n");
  WRITE("<a href=\"https://en.wikipedia.com/wiki/Degrassi:_The_Next_Generation\">Degrassi: The Next Generation</a>\n</font>\nand ranking them from best to worst. I am currently on episode:\n");

  // Currently on episode
  WRITE("</p>\n<p align=\"CENTER\"><span class=\"blink\">\n<span class=\"season8\">\nSeason 8 Episode 8: Lost in Love Part 1\n");

  // Color coded seasons
  WRITE("</span></span></p>\n<p align=\"CENTER\"><font face=\"Comic Sans MS\">I've color coded each episode by their season:\n<br></font>\n");
  WriteSeasons();

  // Episode list
  WRITE("</p><hr>\n<p align=\"CENTER\">\n");
  WriteEpisodes();

  // End of Text in white box
  WRITE("</p></font></td></tr> \n</tbody></table>\n");
  // End of White box
  WRITE("</td></tr></tbody></table>\n");

  WRITE("<table align=\"CENTER\" width=\"60%%\">");
  WRITE("<tbody><tr><td><p align=\"CENTER\">");
  WRITE("<img src=\"http://www.netanimations.net/fire-under-construction-animation.gif\" alt=\"UNDER CONSTRUCTION\">");
  WRITE("</p></td></tr></tbody></table>");

  WRITE("</body>\n");
}

void WriteFooter()
{
  WRITE("<footer>\n");

  WRITE("<table align=\"CENTER\" width=\"100%%\"><tbody><tr><td>");

  WRITE("<table align=\"LEFT\" width=\"100%%\" bgcolor=\"#941001\">");
  WRITE("<tbody><tr><td colspan=\"3\"><font size=\"5\">");
  WRITE("<p align=\"CENTER\"><a href=\"index.html\">~~! Return to homepage !~~</a></p>");
  WRITE("</font><hr><font color=\"#FFFFFF\"><p>Author:christine<br>Copyright 20223</p>");
  WRITE("</font></td></tr></tbody></table></td></tr></tbody></table>");

  WRITE("</footer>\n");
}

void WriteHtml()
{

  // Write to the HTML file
  WRITE("<!DOCTYPE html>\n");
  WRITE("<html>\n");

  WriteHeader();
  WriteBody();
  WriteFooter();

  WRITE("</html>\n");
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

  WriteHtml();

  // Close the HTML file
  fclose(DEGFILE);

  return 1;
}
