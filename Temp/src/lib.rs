
pub mod base;

pub mod queue;

use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    if nums.len() == 0 {
        return vec![];
    };

    if nums.len() == 1 {
        if nums[0] + nums[0] == target {
            return vec![nums[0], nums[0]];
        }
    }

    let mut map: HashMap<i32, usize> = HashMap::new();

    for i in 0..nums.len() {
        if let Some(k) = map.get(&(target - nums[i])) {
            if *k != i {
                return vec![*k as i32, i as i32];
            }
        }
        map.insert(nums[i], i);
    }

    return vec![];
}

// println!("Hello, world!");
// /****
//     // let mut a = String::from("value1");
//     // let addr_a = &a as *const String as usize;
//     // let mut b = String::from("value2");
//     // let addr_b = &b as *const String as usize;
//     // print!("{a} {} | {b} {}\n", addr_a, addr_b);

//     // let t = a;
//     // a = b;
//     // b = t;
//     // print!("{a} {} | {b} {}\n", addr_a, addr_b);
//     // let func = |x: i64| {
//     //     print!("{x}\n");
//     // };
//     // func(42);
//     // (a, b) = (b, a);
//     // print!("{a} {} | {b} {}\n", addr_a, addr_b);
// ****/


// // type q_list = base::List<1, 2, 3>;

// println!("{}", type_name::<<base::False as base::Not>::Ouput>());
