using System;
using System.Collections.Generic;

class AtCoder
{
    public AtCoder() { }
    public static int Main()
    {
        // new AtCoder().calc();
        int val = BMSearch("bbaa", "baa");
        Console.WriteLine(val);
        return 0;
    }

    // BM法
    static int BMSearch(string target, string pattern)
    {
        var table = CreateTable(pattern);

        // 開始位置をパターン末尾に合わせる
        int i = pattern.Length - 1;
        int p = 0;

        while (i < target.Length)
        {
            // パターン末尾に位置を合わせる
            p = pattern.Length - 1;

            while (p >= 0 && i < target.Length)
            {
                if (target[i] == pattern[p])
                {
                    i--; p--;
                }
                else
                {
                    break;
                }
            }
            Console.WriteLine(i);
            Console.WriteLine(p);
            // 一致判定
            if (p < 0) return i + 1;

            // 不一致の場合、ずらし表を参照し i を進める
            // ただし、今比較した位置より後の位置とする
            var shift1 = table.ContainsKey(pattern[p]) ? table[pattern[p]] : pattern.Length;

            var shift2 = pattern.Length - p;    // 比較を開始した地点の1つ後ろの文字
            Console.WriteLine(shift1);
            Console.WriteLine(shift2);
            i += Math.Max(shift1, shift2);
        }

        return -1; // 見つからなかった
    }

    // ずらし表の作成
    static Dictionary<char, int> CreateTable(string pattern)
    {
        // パターン末尾からの距離(小さい幅を優先)
        var table = new Dictionary<char, int>();
        for (int i = 0; i < pattern.Length; i++)
        {
            table[pattern[i]] = pattern.Length - i - 1;
        }
        return table;
    }
}
