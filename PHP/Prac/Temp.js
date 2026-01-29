function add(...numbers){
  sum = 0;
  for(num of numbers){
    sum += num;
  }
  return sum;
}

console.log(add(1,2,4,80,5));