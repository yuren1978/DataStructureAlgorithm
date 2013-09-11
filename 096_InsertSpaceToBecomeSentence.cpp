//http://www.mitbbs.com/article_t1/JobHunting/32174289_0_1.html
//用词典在一个没有空格的句子中插入空格，使它变成合法的句子。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool find_begin_word(string &sentence, vector<string> &dict, vector<int> &space_pos, int pos)
{
  int new_pos = 0;

  bool found = false;
  for ( int i = 0; i < dict.size() && !found; ++i )
  {
    int w_len = dict[i].length();

    if ( pos + w_len <= sentence.length() &&  sentence.substr(pos, w_len) == dict[i] )
    { 
      new_pos = pos + w_len;
      if ( new_pos == sentence.length() )
      {
        space_pos.push_back(pos);
        return true;
      }
      else
      {
        if ( find_begin_word(sentence, dict, space_pos, new_pos) )
        {
          space_pos.push_back(pos);
          return true;
        }
      }
    }
  }

  return false;
}

int main()
{
  vector<string> dict;
  dict.push_back("a");
  dict.push_back("ab");
  dict.push_back("c");

  string sentence("abcab");

  vector<int> space_pos;

  if ( find_begin_word(sentence, dict, space_pos, 0) )
  {
    for ( int i = 0; i < space_pos.size(); ++i )
      cout << space_pos[i] << endl;
  }
}