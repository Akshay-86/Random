let gus = document.getElementById("gus");
let rgteller = document.getElementById("rgteller");
let min = Math.floor(Math.random()*50)+1;
let max = Math.floor(Math.random()*(100 - 51 +1)+51);
let number= Math.floor(Math.random()*(max-min+1)+min);
let inf = document.getElementById("inf");
let chs = 1;

inf.textContent =`Guess the random number between ${min} and ${max}`;

gus.onclick = function(){
  let num = Number(document.getElementById("num").value);
  if(num==``){
    rgteller.textContent =`Plz Enter a number`;
  }else if(num < min || num > max){
    rgteller.textContent =`Plz Enter a valid number`;
  }else if(num > number){
    rgteller.textContent =`Number is too big`;
    chs++;
  }else if(num < number){
    rgteller.textContent =`Number is too small`;
    chs++;
  }else{
    rgteller.textContent =`Congrats, it is correct. It took u ${chs} attempts`;
  }
}