/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function() {
    return "Hello World";
  };
}

// Usage:
const helloFunc = createHelloWorld();
console.log(helloFunc());  // Output: Hello World
/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */