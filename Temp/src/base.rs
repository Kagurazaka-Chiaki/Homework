pub struct Nil;

pub struct True;

pub struct False;

pub trait Bool {}

impl Bool for True {}

impl Bool for False {}

pub trait Not {
    type Ouput: Bool;
}

impl Not for True {
    type Ouput = False;
}

impl Not for False {
    type Ouput = True;
}

pub trait Or {
    type Ouput: Bool;
}

impl Or for (True, False) {
    type Ouput = True;
}

impl Or for (True, True) {
    type Ouput = True;
}

impl Or for (False, True) {
    type Ouput = True;
}

impl Or for (False, False) {
    type Ouput = False;
}

pub trait And {
    type Ouput: Bool;
}

impl And for (True, False) {
    type Ouput = False;
}

impl And for (True, True) {
    type Ouput = True;
}

impl And for (False, True) {
    type Ouput = False;
}

impl And for (False, False) {
    type Ouput = False;
}

#[allow(dead_code)]
trait Xor {
    type Ouput: Bool;
}

pub struct List<T>(T);

pub trait Container {
    type Output;
}

impl<T> Container for List<T> {
    type Output = Vec<i32>;
}

// trait ListConcat {
//     type Output;
// }

// impl<L2> ListConcat for (Nil, L2) {
//     type Output = L2;
// }

// impl<X, Xs, L2> ListConcat for (Cons<X, Xs>, L2)
// where
//     (Xs, L2): ListConcat,
// {
//     type Output = Cons<X, <(Xs, L2) as ListConcat>::Output>;
// }
