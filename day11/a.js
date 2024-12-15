const fs = require('fs');

let data;
try {
    data = fs.readFileSync('day11/data.txt', 'utf8');
    console.log(data);
} catch (err) {
    console.error(err.message);
}

data = data.split(" ");
console.log(typeof data);


let k = 1;
while (k <= 25) {
    for (let i = 0; i < data.length; i++) {
        if (Number(data[i]) == 0) {
            data[i] = "1";
        }
        else if (data[i].length % 2 == 0) {
            let mid = data[i].length / 2;
            let stone1 = (Number(data[i].slice(0, mid))).toString();
            let stone2 = (Number(data[i].slice(mid))).toString();
            data.splice(i, 1);
            data.splice(i, 0, stone1, stone2);
            i++;
        }
        else {
            data[i] = (Number(data[i]) * 2024).toString();
        }
    }
    k++;
}

console.log(data.length);