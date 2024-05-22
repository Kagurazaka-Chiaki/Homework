use std::{
    fs,
    // io::{prelude::*, BufReader},
    // sync::{mpsc, Arc, Mutex},
    // thread,
};
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::TcpStream;

// struct Worker {
//     id: usize,
//     thread: Option<thread::JoinHandle<()>>,
// }

// impl Worker {
//     fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Job>>>) -> Worker {
//         let thread = thread::spawn(move || loop {
//             // let job = receiver.lock().unwrap().recv().unwrap();

//             // println!("Worker {id} got a job; executing.");
//             let message = receiver.lock().unwrap().recv();
//             match message {
//                 Ok(job) => {
//                     println!("Worker {id} got a job; executing.");

//                     job();
//                 }
//                 Err(_) => {
//                     println!("Worker {id} disconnected; shutting down.");
//                     break;
//                 }
//             }
//             // job();
//         });

//         Worker {
//             id,
//             thread: Some(thread),
//         }
//     }
// }

// type Job = Box<dyn FnOnce() + Send + 'static>;

// struct ThreadPool {
//     workers: Vec<Worker>,
//     sender: Option<mpsc::Sender<Job>>,
// }

// impl ThreadPool {
//     pub fn new(capacity: usize) -> ThreadPool {
//         assert!(capacity > 0);

//         let (sender, receiver) = mpsc::channel();

//         let receiver = Arc::new(Mutex::new(receiver));

//         let mut workers = Vec::with_capacity(capacity);

//         for id in 0..capacity {
//             workers.push(Worker::new(id, Arc::clone(&receiver)));
//         }

//         ThreadPool {
//             workers,
//             sender: Some(sender),
//         }
//     }

//     pub fn execute<F>(&self, f: F)
//     where
//         F: FnOnce() + Send + 'static,
//     {
//         let job = Box::new(f);

//         self.sender.as_ref().unwrap().send(job).unwrap();
//     }
// }

// impl Drop for ThreadPool {
//     fn drop(&mut self) {
//         drop(self.sender.take());

//         for worker in &mut self.workers {
//             println!("Shutting down worker {}", worker.id);

//             if let Some(thread) = worker.thread.take() {
//                 thread.join().unwrap();
//             }
//         }
//     }
// }

// struct Request {
//     head: String,
//     host: String,
//     connection: String,
//     cache_control: String,
// }

#[tokio::main]
async fn main() {
    let listener = tokio::net::TcpListener::bind("127.0.0.1:7878")
        .await
        .unwrap();

    // let pool = ThreadPool::new(4);

    while let Ok((stream, _)) = listener.accept().await {
        // pool.execute(async move {
        //     handle_connection(stream).await;
        // });
        handle_connection(stream).await;
    }
}

async fn handle_connection(mut stream: TcpStream) {
    // let buf_reader = BufReader::new(&mut stream);
    // let request_line = buf_reader.lines().next().unwrap().unwrap();

    let mut buffer = [0; 1024];
    stream.read(&mut buffer).await.unwrap();

    let request = String::from_utf8_lossy(&buffer[..]);

    // println!("Request: [{}]", request);

    let request_head = request.lines().next().unwrap();

    let (status_line, filename) = if request_head == "GET / HTTP/1.1" {
        ("HTTP/1.1 200 OK", "hello.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND", "404.html")
    };

    let contents = fs::read_to_string(filename).unwrap();
    let length = contents.len();

    let response = format!("{status_line}\r\nContent-Length: {length}\r\n\r\n{contents}");

    println!("Response: [{}]", response);

    stream.write_all(response.as_bytes()).await.unwrap();
}

// use std::collections::HashMap;
// use std::sync::{Arc, Mutex, RwLock};
// use std::thread;

// #[derive(Debug, Clone, PartialEq)]
// pub enum NodeType {
//     Val(f32),
//     None,
// }

// #[derive(Debug, Clone)]
// pub struct Graph {
//     vertex: Vec<usize>,
//     edge: Vec<(usize, usize)>,
//     matrix: Vec<Vec<NodeType>>,
// }

// impl Graph {
//     pub fn new(m: i32, n: i32) -> Self {
//         Self {
//             vertex: vec![],
//             edge: vec![],
//             matrix: vec![vec![NodeType::None; n as usize]; m as usize],
//         }
//     }
// }

// #[derive(Debug)]
// pub struct Sheet {
//     graph: Graph,
//     // data: RwLock<HashMap<String, Data>>,
//     data: RwLock<HashMap<String, (i32, i32)>>,
// }

// impl Sheet {
//     pub fn new(row: i32, col: i32) -> Self {
//         Self {
//             graph: Graph::new(row, col),
//             data: RwLock::new(HashMap::new()),
//         }
//     }

//     pub fn set_data() {}
// }

// fn main() {
//     let counter = Arc::new(Mutex::new(Sheet::new(0, 0)));
//     let mut handles = vec![];

//     for _ in 0..10 {
//         let counter = Arc::clone(&counter);
//         let handle = thread::spawn(move || {
//             let mut num = counter.lock().unwrap();

//             let mut w = num.data.write().unwrap();
//             w.insert(String::from("value"), (1, 1))
//         });
//         handles.push(handle);
//     }

//     for handle in handles {
//         handle.join().unwrap();
//     }

//     let r = counter.lock().unwrap();
//     let rr = r.data.read().unwrap();

//     let ans = rr.get("value").unwrap();

//     println!("Result: {}", ans.0);
// }
