using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;

namespace dotnet
{
    public class Reader
    {
        private Dictionary<string, int> dictionary;

        public Reader()
        {
            dictionary = new Dictionary<string, int>();
        }

        public void Read(string filepath)
        {
            FileStream fileStream = new FileStream(filepath, FileMode.Open);
            using (StreamReader reader = new StreamReader(fileStream))
            {
                while(!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    foreach (var word in line.Split())
                    {
                        var newWord = RemoveSpecials(word);
                        if(!IsEmpty(newWord))
                        {
                            newWord = newWord.ToLower();
                            Increment(newWord);
                            System.Console.WriteLine(newWord);
                        }
                    }
                }
            }
        }

        private bool IsEmpty(string word)
        {
            return word == null || word.Length < 1;
        }

        private void Increment(string word)
        {
            if(dictionary.ContainsKey(word))
            {
                dictionary[word] = dictionary[word] + 1;
            }
            else
            {
                dictionary.Add(word, 1);
            }
        }

        private string RemoveSpecials(string word)
        {
            string result = Regex.Replace(word, "[^a-zA-Z]", "");
            return result;
        }   

        public void PrintDictionary()
        {
            foreach( KeyValuePair<string, int> pair in dictionary.OrderBy(n => n.Value))
            {
                System.Console.WriteLine($"Key = {pair.Key}, Value = {pair.Value}");
            }
        }
    }
}