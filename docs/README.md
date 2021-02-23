# Snake game using C++
I created a snake game using C++, without the use of any graphics library.<br>
To see how this games looks and work <br>

<iframe width="560" height="315" src="https://www.youtube.com/embed/HlmdeXelTsM" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<div style="position: relative;width: 100%;max-width:600px;eight: 0;padding-bottom: 56.25%;">
<iframe style="position: absolute;top: 0;left: 0;width: 100%;height: 100%;" src="https://www.youtube.com/embed/HlmdeXelTsM" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

I used following libraries-<br>
<ol>
<li>conio.h</li>
<li> time.h </li>
<li> synchapi.h </li>
<li> windows.h </li>
</ol>

The code **[snake.cpp](https://github.com/Mysterious-Owl/Snake-game-using-C/blob/master/snake.cpp) is final game** consists of *all features*, which is too efficient and its speed is great (you can't play custom: 0), it doesn't have screen flickering issues, the size of board can be increased without compromising the effciency of game.
<br><br>
## Features-

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
</ul></ul>
<br>
The other code <a href="https://github.com/Mysterious-Owl/Snake-game-using-C/blob/master/snake_naive_approach.cpp"> snake_naive_approach.cpp</a> is the naive approach to this game, which I formed initially, it overwrites the whole screen and then writes it, then clears then writes it, so its not so efficient, slow but has a smaller code (almost half).
