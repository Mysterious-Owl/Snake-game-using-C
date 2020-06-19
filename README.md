# Snake game using C++
I created a snake game using C++, without the use of any graphics library.<br>
To see how this games looks and work-[Youtube link](https://youtu.be/HlmdeXelTsM) <br>
I used following libraries-<br>
<ol>
 <li>conio.h</li>
<li> time.h </li>
<li> synchapi.h </li>
<li> windows.h </li>
</ol>

The code **[snake.cpp](https://github.com/Mysterious-Owl/Snake-game-using-C/blob/master/snake.cpp) is final game** consists of *all features*, which is too efficient and its speed is great (you can't play custom: 0), it doesn't have screen flickering issues, the size of board can be increased without compromising the effciency of game.<br><br>Features-<br>

<ul>
<li> Various difficulty mode- Easy, Medium (Default), Hard, Custom (set the time in milliseconds)</li>
<li> P can pause the game</li>
<li> S can open the settings of game in exit screen or in welcome screen.</li>
<li> C can end the game</li>
<li> esc is used to exit the game at exit screen</li>
<li> It has many settings to modify the game.</li><ul>
<li> Can pass though walls (modify in settings) (Default- No)</li>
<li> Can go reverse (modify in settings) (Default- No)</li>
<li> Can't die by touching its own body (modify in settings) (Default- No)</li>
<li> Change the dimensions of board (modify in settings) (Default- 27 118)</li>
<li> Two modes- Board can be made up of colours or of characters (modify in settings) (Default- Colour)</li>
</ul></ul><br>
The other code <a href="https://github.com/Mysterious-Owl/Snake-game-using-C/blob/master/snake_naive_approach.cpp"> snake_naive_approach.cpp</a> is the naive approach to this game, which I formed initially, it overwrites the whole screen and then writes it, then clears then writes it, so its not so efficient, slow but has a smaller code (almost half).
