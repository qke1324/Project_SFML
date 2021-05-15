#pragma once

#include <SFML/Audio.hpp>

#include "Math.h"

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

#define SAFE_DELETE(x) if((x)) delete (x); (x) = nullptr