

use temp::queue;


fn main() {
    println!("Hello, world!");
    /****
        // let mut a = String::from("value1");
        // let addr_a = &a as *const String as usize;
        // let mut b = String::from("value2");
        // let addr_b = &b as *const String as usize;
        // print!("{a} {} | {b} {}\n", addr_a, addr_b);

        // let t = a;
        // a = b;
        // b = t;
        // print!("{a} {} | {b} {}\n", addr_a, addr_b);
        // let func = |x: i64| {
        //     print!("{x}\n");
        // };
        // func(42);
        // (a, b) = (b, a);
        // print!("{a} {} | {b} {}\n", addr_a, addr_b);
    ****/


    // type q_list = base::List<1, 2, 3>;

    // println!("{}", type_name::<<base::False as base::Not>::Ouput>());


    let mut list = queue::List::new();

    // Check empty list behaves right
    assert_eq!(list.pop_front(), None);

    // Populate list
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    // Check normal removal
    assert_eq!(list.pop_front(), Some(3));
    assert_eq!(list.pop_front(), Some(2));

    // Push some more just to make sure nothing's corrupted
    list.push_front(4);
    list.push_front(5);

    // Check normal removal
    assert_eq!(list.pop_front(), Some(5));
    assert_eq!(list.pop_front(), Some(4));

    // Check exhaustion
    assert_eq!(list.pop_front(), Some(1));
    assert_eq!(list.pop_front(), None);

    // ---- back -----

    // Check empty list behaves right
    assert_eq!(list.pop_back(), None);

    // Populate list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Check normal removal
    assert_eq!(list.pop_back(), Some(3));
    assert_eq!(list.pop_back(), Some(2));

    // Push some more just to make sure nothing's corrupted
    list.push_back(4);
    list.push_back(5);

    // Check normal removal
    assert_eq!(list.pop_back(), Some(5));
    assert_eq!(list.pop_back(), Some(4));

    // Check exhaustion
    assert_eq!(list.pop_back(), Some(1));
    assert_eq!(list.pop_back(), None);

}
