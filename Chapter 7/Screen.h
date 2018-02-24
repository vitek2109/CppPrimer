#ifndef SCREEN
#define SCREEN
#include <iostream>
#include <string>
#include <vector>

class Screen {
public:
	friend class Window_mgr;
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos h, pos w): height(h), width(w), contents(w*h, ' ') {}
	Screen(pos h, pos w, char c): height(h), width(w), contents(w*h, c) {}
	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const;
	Screen &set(char c);
	Screen &set(pos r, pos c, char ch);
	Screen &move(pos r, pos c);
	Screen &display(std::ostream &out) { do_display(out); return *this; }
	const Screen &display(std::ostream &out) const { do_display(out); return *this; }
private:
	void do_display (std::ostream &out) const;
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

class Window_mgr {
public:
	typedef std::vector<Screen>::size_type ScreenIndex;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens = {Screen(5, 5, 'X')};
};

void Window_mgr::clear(ScreenIndex index) {
	Screen &s = screens[index];
	s.contents = std::string(s.height * s.width, ' ');
}

inline char Screen::get(pos r, pos c) const
{
	return contents[r*width + c];
}

inline Screen &Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}

Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen &Screen::set(pos r, pos c, char ch)
{
	contents[r*width + c] = ch;
	return *this;
}

void Screen::do_display (std::ostream &out) const
{
	for (pos i = 0; i < height * width; ++i)
	{
		if (i % width == 0)
			out << '\n';
		out << contents[i];
	}
}
#endif