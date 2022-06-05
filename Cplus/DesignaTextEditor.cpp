#include <list>
#include <string>
using namespace std;

class TextEditor
{
public:
	TextEditor()
	{
		data.push_back('!'); //dummy char
		cursor = data.end();
	}

	void addText(string text)
	{
		data.insert(cursor, text.begin(), text.end());
	}

	int deleteText(int k)
	{
		int res = 0;
		auto it = prev(cursor);
		for (; res < k && it != data.begin(); ++res)
			--it;
		data.erase(++it, cursor);
		return res;
	}

	string cursorLeft(int k)
	{
		auto first = ++data.begin();
		for (int i = 0; i < k && cursor != first; ++i)
			--cursor;

		string res;
		auto it = prev(cursor);
		for (; res.size() < LEN && it != data.begin();)
		{
			res.push_back(*it);
			--it;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	string cursorRight(int k)
	{
		for (int i = 0; i < k && cursor != data.end(); ++i)
			++cursor;

		string res;
		auto it = prev(cursor);
		for (; res.size() < LEN && it != data.begin();)
		{
			res.push_back(*it);
			--it;
		}
		reverse(res.begin(), res.end());
		return res;
	}

private:
	const int LEN = 10;
	list<char> data;
	list<char>::iterator cursor;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */