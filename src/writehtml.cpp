#include <stdio.h>
#include <stdlib.h>

FILE* DEGFILE;

void WRITE(const char* str)
{
  fprintf(DEGFILE, str);
}

void WriteEpisodes()
{
  FILE* epListFile;

  epListFile = fopen("episodelist.txt", "r");
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
  WRITE(".season1 {color: blue;font-family: courier;font-size: 120%;}\n");
  WRITE(".season2 {color: green;font-family: comic sans ms;}\n");
  WRITE(".season3 {color: red;font-family: trebuchet ms;}\n");
  WRITE(".season4 {color: black;font-family: garamond;font-size: 110%;}\n");
  WRITE(".season5 {color: purple;font-family: brush script mt;font-size: 120%;}\n");
  WRITE(".season6 {color: brown;font-family: courier;font-size: 110%;}\n");
  WRITE(".season7 {color: yellow;font-family: comic sans ms;}\n");
  WRITE(".season8 {color: blue;font-family: garmond;}\n");
  WRITE("</style\n");
}

void WriteHeader()
{
  WRITE("<head>\n");

  WRITE("<meta name=\"GENERATOR\" content=\"Vim\">\n");
  WRITE("<title>DEGRASSI RANKING EH</title>\n");
  WRITE("<link rel=\"icon\" href=\"../images/jtyorke.ico\">\n");

  WriteStyle();

  WRITE("</head>\n");
}

void WriteBody()
{
  WRITE("<body>\n");

  WRITE("<body bgcolor=\"FFF6F0\" background=\"../images/paige.gif\" text= \"#C41502\">\n");
  WRITE("<basefont face=\"Times,Courier\">\n");

  // Header DEGRASSI RANKING EH! on top of page
  WRITE("<table align=\"CENTER\" width=\"80%\">\n");
  WRITE("<tbody>\n<tr><td>\n<font size=\"5\">\n<h1 align=\"CENTER\">\n");
  WRITE("<blink>\n<marquee behavior=\"ALTERNATE\">\nDEGRASSI RANKING EH!\n");
  WRITE("</marquee>\n</blink>\n</h1>\n</font>\n</td></tr>\n</tbody>\n</table>\n");


  // White box with episode list
  WRITE("<table align=\"CENTER\" width=\"60\%\">\n<tbody>\n<tr><td>\n");
  WRITE("<table align=\"CENTER\" width=\"100%\" bgcolor=\"#FFFFFF\">\n<tbody>\n<tr><td colspan=\"3\">\n<font size=\"4\">\n");

  // Intro to ranking
  WRITE("<p align=\"CENTER\">\nHeey! I've been rewatching all the episodes of\n <font face=\"Comic Sans MS\" size=\"5\" color=\"#000000\">\n");
  WRITE("<a href=\"https://en.wikipedia.com/wiki/Degrassi:_The_Next_Generation\">Degrassi: The Next Generation</a>\n</font>\nand ranking them. I am currently on episode:\n");

  // Currently on episode
  WRITE("</p>\n<p align=\"CENTER\"><span class=\"blink\">\n<span class=\"season8\">\nSeason 8 Episode 7: Money for Nothing\n");

  // Color coded seasons
  WRITE("</span></span></p>\n<p align=\"CENTER\"><font face=\"Comic Sans MS\">I've color coded each episode by their season:\n<br></font>\n");
  //<a href="season/season1.html" style="text-decoration: none"><span class="season1">Season 1</span></a><br>

  WRITE("</p><hr>\n<p align=\"CENTER\">\n");

  // List all the episodes here
  //<span class="season4">Time Stands Still Pt. 2</span><br>
  WriteEpisodes();
  // /Text in white box
  WRITE("</p></font></td></tr> \n</tbody></table>\n");
  // /White box
  WRITE("</td></tr></tbody></table>\n");


  WRITE("</body>\n");
}

void WriteFooter()
{
  WRITE("<footer>\n");


  WRITE("</footer>\n");
}

void WriteHtml()
{
  // Open the HTML file
  DEGFILE = fopen("degrassinextgenerated.html", "w");


  // Write to the HTML file
  WRITE("<!DOCTYPE html>\n");
  WRITE("<html>\n");

  WriteHeader();
  WriteBody();
  WriteFooter();

  WRITE("</html>\n");

  // Close the HTML file
  fclose(DEGFILE);
}


int main(int argc, char* argv[])
{
  WriteHtml();

  return 1;
}
