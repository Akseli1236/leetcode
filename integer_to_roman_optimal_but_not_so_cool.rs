struct Solution;


impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        let roman_numbers = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ];

        let mut result = String::new();

        for &(value, symbol) in roman_numbers.iter() {
            while num >= value {
                result.push_str(symbol);
                num -= value;
            }
        }

        result
    }
}

fn main() {
    let result = Solution::int_to_roman(3749);

    println!("{result}");

    let result = Solution::int_to_roman(58);

    println!("{result}");

    let result = Solution::int_to_roman(1994);

    println!("{result}");

    let result = Solution::int_to_roman(10);

    println!("{result}");

    let result = Solution::int_to_roman(80);

    println!("{result}");
}
