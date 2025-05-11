#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

const vector<vector<string>> digits_7x7_star = {
	{// 0
	 "*******",
	 "*.....*",
	 "*.....*",
	 "*.....*",
	 "*.....*",
	 "*.....*",
	 "*******"},
	{// 1
	 "....*..",
	 "....*..",
	 "....*..",
	 "....*..",
	 "....*..",
	 "....*..",
	 "....*.."},
	{// 2
	 "*******",
	 "......*",
	 "......*",
	 "*******",
	 "*......",
	 "*......",
	 "*******"},
	{// 3
	 "*******",
	 "......*",
	 "......*",
	 "*******",
	 "......*",
	 "......*",
	 "*******"},
	{// 4
	 "*.....*",
	 "*.....*",
	 "*.....*",
	 "*******",
	 "......*",
	 "......*",
	 "......*"},
	{// 5
	 "*******",
	 "*......",
	 "*......",
	 "*******",
	 "......*",
	 "......*",
	 "*******"},
	{// 6
	 "*******",
	 "*......",
	 "*......",
	 "*******",
	 "*.....*",
	 "*.....*",
	 "*******"},
	{// 7
	 "*******",
	 "......*",
	 "......*",
	 "......*",
	 "......*",
	 "......*",
	 "......*"},
	{// 8
	 "*******",
	 "*.....*",
	 "*.....*",
	 "*******",
	 "*.....*",
	 "*.....*",
	 "*******"},
	{// 9
	 "*******",
	 "*.....*",
	 "*.....*",
	 "*******",
	 "......*",
	 "......*",
	 "*******"}};

const vector<vector<string>> digits_5x5_star = {
	{// 0
	 "*****",
	 "*...*",
	 "*...*",
	 "*...*",
	 "*****"},
	{// 1
	 "..*..",
	 "..*..",
	 "..*..",
	 "..*..",
	 "..*.."},
	{// 2
	 "*****",
	 "....*",
	 "*****",
	 "*....",
	 "*****"},
	{// 3
	 "*****",
	 "....*",
	 "*****",
	 "....*",
	 "*****"},
	{// 4
	 "*...*",
	 "*...*",
	 "*****",
	 "....*",
	 "....*"},
	{// 5
	 "*****",
	 "*....",
	 "*****",
	 "....*",
	 "*****"},
	{// 6
	 "*****",
	 "*....",
	 "*****",
	 "*...*",
	 "*****"},
	{// 7
	 "*****",
	 "....*",
	 "....*",
	 "....*",
	 "....*"},
	{// 8
	 "*****",
	 "*...*",
	 "*****",
	 "*...*",
	 "*****"},
	{// 9
	 "*****",
	 "*...*",
	 "*****",
	 "....*",
	 "*****"}};

const vector<string> equals_7x7_star = {
	".......",
	".......",
	"*******",
	".......",
	"*******",
	".......",
	"......."};

const vector<string> inf_I_7x7_star = {
	"*******",
	"...*...",
	"...*...",
	"...*...",
	"...*...",
	"...*...",
	"*******"};

const vector<string> inf_N_7x7_star = {
	"*.....*",
	"**....*",
	"*. *..*",
	"*..*..*",
	"*...*.*",
	"*....**",
	"*.....*"};

const vector<string> inf_F_7x7_star = {
	"*******",
	"*......",
	"*......",
	"*******",
	"*......",
	"*......",
	"*......"};


ull power_with_overflow_check(ull base, ull exp, ull limit, bool &overflow_flag)
{
	overflow_flag = false;
	if (base == 1)
	{ // 1 to any power is 1
		return 1;
	}
	// Since x, y are positive, base >= 1 and exp >= 1.
	// If base == 0, it's not covered by problem constraints but would be 0.

	ull result = 1;
	for (ull i = 0; i < exp; ++i)
	{
		// Check for overflow before multiplication: result * base > limit
		// This is equivalent to result > limit / base, if base > 0
		if (base > 0 && result > limit / base)
		{
			overflow_flag = true;
			return limit + 1; // Actual value doesn't matter if overflowed
		}
		result *= base;
	}
	return result;
}

void plot_char_on_canvas(vector<string> &canvas, const vector<string> &char_pattern_star, char fill_character, int top_offset, int col_start_on_canvas)
{
	int pattern_h = char_pattern_star.size();
	if (pattern_h == 0)
		return;
	int pattern_w = char_pattern_star[0].size();

	for (int r = 0; r < pattern_h; ++r)
	{
		for (int c = 0; c < pattern_w; ++c)
		{
			// Basic bounds check, though canvas should be pre-sized
			if (top_offset + r < canvas.size() && col_start_on_canvas + c < canvas[0].size())
			{
				if (char_pattern_star[r][c] == '*')
				{
					canvas[top_offset + r][col_start_on_canvas + c] = fill_character;
				}
			}
		}
	}
}

void solve()
{
	string expression_string;
	cin >> expression_string;

	size_t caret_pos = expression_string.find("^{");
	string x_str = expression_string.substr(0, caret_pos);
	size_t close_brace_pos = expression_string.find("}");
	string y_str = expression_string.substr(caret_pos + 2, close_brace_pos - (caret_pos + 2));

	ull x_val = stoull(x_str);
	ull y_val = stoull(y_str);

	ull calculation_limit = 1000000000000000000ULL; // 10^18
	bool did_overflow = false;
	ull z_val = power_with_overflow_check(x_val, y_val, calculation_limit, did_overflow);

	string z_to_render_str;
	if (did_overflow)
	{
		z_to_render_str = "INF";
	}
	else
	{
		z_to_render_str = to_string(z_val);
	}

	int total_canvas_width = 1; // Initial left padding
	for (char ch : x_str)
		total_canvas_width += (7 + 1); // char_width + space_width
	for (char ch : y_str)
		total_canvas_width += (5 + 1);
	total_canvas_width += (7 + 1); // For '='
	for (char ch : z_to_render_str)
		total_canvas_width += (7 + 1);

	vector<string> canvas(10, string(total_canvas_width, '.'));
	int current_drawing_col = 1; // Start plotting after left padding

	// Draw x
	for (char xc : x_str)
	{
		plot_char_on_canvas(canvas, digits_7x7_star[xc - '0'], xc, 2, current_drawing_col);
		current_drawing_col += 7; // Advance by char width
		current_drawing_col++;	  // Advance by space width
	}

	// Draw y (exponent)
	for (char yc : y_str)
	{
		plot_char_on_canvas(canvas, digits_5x5_star[yc - '0'], yc, 1, current_drawing_col);
		current_drawing_col += 5;
		current_drawing_col++;
	}

	// Draw =
	plot_char_on_canvas(canvas, equals_7x7_star, '=', 2, current_drawing_col);
	current_drawing_col += 7;
	current_drawing_col++;

	// Draw z or INF
	if (did_overflow)
	{
		plot_char_on_canvas(canvas, inf_I_7x7_star, 'I', 2, current_drawing_col);
		current_drawing_col += 7;
		current_drawing_col++;
		plot_char_on_canvas(canvas, inf_N_7x7_star, 'N', 2, current_drawing_col);
		current_drawing_col += 7;
		current_drawing_col++;
		plot_char_on_canvas(canvas, inf_F_7x7_star, 'F', 2, current_drawing_col);
		current_drawing_col += 7;
		current_drawing_col++;
	}
	else
	{
		for (char zc : z_to_render_str)
		{
			plot_char_on_canvas(canvas, digits_7x7_star[zc - '0'], zc, 2, current_drawing_col);
			current_drawing_col += 7;
			current_drawing_col++;
		}
	}

	for (const string &canvas_row : canvas)
	{
		cout << canvas_row << endl;
	}
	cout << endl; // Blank line after each test case's output
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
