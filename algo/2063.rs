impl Solution {
    pub fn count_vowels(word: String) -> i64 {
        let mut cnt = 0i64;
        let mut ans = 0i64;
        for (i, c) in word.char_indices() {
            cnt += match c {
                'a' | 'e' | 'i' | 'o' | 'u' => i as i64 + 1,
                _ => 0,
            };
            ans += cnt;
            // println!("{:?} cnt {:} ", ans, cnt)
        }
        ans
    }
}