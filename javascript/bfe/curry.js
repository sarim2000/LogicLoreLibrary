/*
    CURRYING!!!

    What? 
    --> Using Currying we can modify a function from f(a,b) to f(a)(b)
*/

//basic example

const ingredients = (ingred1) => {
    return (ingred2) => {
        return (ingred3) => {
            return `${ingred1} ${ingred2} ${ingred3}`
        }
    }
}

console.log(ingredients("bread")("butter")("egg")) 
// bread butter egg


console.log(ingredients("bread")("butter")) 
// its expecting a third argument
/*
(ingred3) => {
    return `${ingred1} ${ingred2} ${ingred3}`
}
*/

//advance curry implementation or wrapper

function curry(fn){
    return function curried(...args) {
        // 1. if number of args are similar to function then we can directly call that
        // 2. if not, then we have to bind the current number of arguments to curried function and wait

        if (args.length >= fn.length){
            return fn.apply(this,args)
        }
        else{
            return curried.bind(this,...args)
        }
    }
}

// using above curry function

const sum = (a,b) => a + b
const multiply = (a, b) => a * b


const currySum      = curry(sum)
const curryMultiply = curry(multiply)

console.log(currySum(2)(3))
// 5
console.log(curryMultiply(2)(3))
//6


// real life example

function applyDiscount(discount) {
    return function (price) {
        return price - price * discount;
    }
}

// Curried discount functions
let electronicsDiscount = applyDiscount(0.10);
let clothingDiscount = applyDiscount(0.20);

// Applying discounts
let discountedPriceForElectronics = electronicsDiscount(1000); // Price after 10% discount
let discountedPriceForClothing = clothingDiscount(500);        // Price after 20% discount
