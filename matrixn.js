function insertBox () {


}

let coeffMatrix = [];

function createMatrix () {
varCount = document.getElementById("counter").value;

for (let i=0; i<varCount; i++)
    coeffMatrix[i] = new Array(varCount);

for (let j=0; j<varCount; j++) {
    for (let i=0; i<varCount; i++) {
        coeffMatrix[i][j] = 0;
    }
}

console.log(coeffMatrix);

document.getElementById('matrix').innerHTML = coeffMatrix;
}

