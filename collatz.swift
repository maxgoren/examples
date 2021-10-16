//
//  main.swift
//  collatz
//
//  Created by max goren on 10/16/21.
//  Copyright © 2021 maxgcoding.com via MIT Liecense
//

import Foundation

func isEven(num: Int) -> Bool {
    return (num % 2 == 0) ? true:false;
}

func collatz(_ k: Int, _ count: Int) -> Int {
    if (k == 1) {
        print(k)
        return count
    }
    let inc = count + 1
    print("\(k)", "-> ", terminator: "")
    if (isEven(num: k)) {
        return collatz(k/2, inc)
    } else {
        return collatz((k*3)+1, inc)
    }
}

for i in 1...5 {
   let result = collatz(i, 0)
       print("Collatz Conjecture starting interval of \(i) generated \(result) integer sequence.")
    }
}
