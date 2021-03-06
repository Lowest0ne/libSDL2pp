/*
  libSDL2pp - C++ wrapper for libSDL2
  Copyright (C) 2013 Dmitry Marakasov <amdmi3@amdmi3.ru>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include <cassert>

#include <SDL2/SDL_rect.h>

#include <SDL2pp/Point.hh>

namespace SDL2pp {

Point::Point() {
}

Point::~Point() {
}

Point::Point(int x, int y) : point_(new SDL_Point) {
	point_->x = x;
	point_->y = y;
}

Point Point::Null() {
	return Point();
}

Point::Point(const Point& other) {
	if (other.point_.get()) {
		point_.reset(new SDL_Point);
		point_->x = other.point_->x;
		point_->y = other.point_->y;
	}
}

Point& Point::operator=(const Point& other) {
	if (other.point_.get()) {
		point_.reset(new SDL_Point);
		point_->x = other.point_->x;
		point_->y = other.point_->y;
	}
	return *this;
}

SDL_Point* Point::Get() {
	return point_.get();
}

const SDL_Point* Point::Get() const {
	return point_.get();
}

bool Point::IsNull() const {
	return point_ == nullptr;
}

int Point::GetX() const {
	assert(!IsNull());
	return point_->x;
}

int Point::GetY() const {
	assert(!IsNull());
	return point_->y;
}

void Point::Swap(Point& other) noexcept {
	point_.swap(other.point_);
}

}
