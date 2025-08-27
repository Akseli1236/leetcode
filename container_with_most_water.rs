use std::cmp;
struct Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut j = height.len() - 1;
        let mut area = 0;

        while i < j {
            let width = (j - i) as i32;
            let h = cmp::min(height[i], height[j]);
            area = cmp::max(area, h * width);

            if height[i] < height[j] {
                i += 1;
            } else {
                j -= 1;
            }
        }

        area
    }
}


fn main() {

    let height = [1,8,6,2,5,4,8,3,7];

    let result = Solution::max_area(height.to_vec());

    println!("{result}");

    let height = [4,3,2,1,4];

    let result = Solution::max_area(height.to_vec());

    println!("{result}")

}
