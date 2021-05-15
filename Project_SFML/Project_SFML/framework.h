#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

constexpr float PI = 3.14159265f;

#define SAFE_DELETE(x) if((x)) delete (x); (x) = nullptr