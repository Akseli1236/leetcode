struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let roman_numbers: HashMap<_, _> = [
            (1, "I"),
            (5, "V"),
            (10, "X"),
            (50, "L"),
            (100, "C"),
            (500, "D"),
            (1000, "M"),
        ]
        .into_iter()
        .collect();

        let mut temp_num = num;
        let mut degree = 1;
        let mut final_string = String::new();

        while temp_num > 0 {
            let digit = (temp_num % 10) * degree;

            let (k, v) = roman_numbers
                .iter()
                .min_by_key(|&(&k, _)| {

                    if k - digit > 0 && (k-digit).abs() / degree == 2 {
                        5_000
                    }else{
                        (k - digit).abs()
                    }
                })
                .map(|(&k, &v)| (k, v))
                .unwrap();

            let mut off_by = 0;

            if k < digit {
                off_by = digit - k;
                for _ in 0..off_by / degree {
                    final_string.push_str(roman_numbers[&degree]);
                }
                final_string.push_str(v);
            } else if digit != 0 {
                final_string.push_str(v);
                off_by = k - digit;
                for _ in 0..off_by / degree {
                    final_string.push_str(roman_numbers[&degree]);
                }
            }

            println!(
                "Closest to {} is {} -> {}, {}",
                digit,
                k,
                v,
                off_by / degree
            );

            temp_num = temp_num / 10;
            degree = degree * 10;
        }

        format!("{}", final_string.chars().rev().collect::<String>())
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
