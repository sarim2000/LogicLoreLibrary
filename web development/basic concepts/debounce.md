# debounce

## what is debounce?

Debounce in simplest term is waiting for a fixed amount of time before a function is executed.

simple debounce function

```js
function debounce(fn,t){
    let timer;
    return function(...args){
        clearTimeout(timer);
        timer = setTimeout(()=>{
            fn(...args)
        }, t)
    }
}
```