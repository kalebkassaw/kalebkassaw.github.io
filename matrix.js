function solve(){
let row0 = [0, 0, 0];
let row1 = [0, 0, 0];

row0[0] = Number(document.getElementById("a00").value);
row0[1] = Number(document.getElementById("a01").value);
row1[0] = Number(document.getElementById("a10").value);
row1[1] = Number(document.getElementById("a11").value);

row0[2] = Number(document.getElementById("a02").value);
row1[2] = Number(document.getElementById("a12").value);

console.log(row0);
console.log(row1);

if (row0[0] != 1) {
    row0[1] = row0[1] / row0[0];
    row0[2] = row0[2] / row0[0];
    // Have to do this one last!!!!
    row0[0] = row0[0] / row0[0];

    console.log('after first op:');
    console.log(row0);
    console.log(row1);
}

if (row1[0] != 0) {
    row1[1] = row1[1] - row1[0]*row0[1];
    row1[2] = row1[2] - row1[0]*row0[2];
    // Again, must be last.
    row1[0] = row1[0] - row1[0]*row0[0];

    console.log('after second op:');
    console.log(row0);
    console.log(row1);
}

if (row1[1] != 1) {
    row1[0] = row1[0] / row1[1];
    row1[2] = row1[2] / row1[1];
    // L A S T
    row1[1] = row1[1] / row1[1];

    console.log('after third op:');
    console.log(row0);
    console.log(row1);
}

if (row0[1] != 0) {
    row0[0] = row0[0] - row0[1]*row1[0];
    row0[2] = row0[2] - row0[1]*row1[2];
    // MUST BE F&%$ING LAST but with a twist (lol)
    row0[1] = row0[1] - row0[1]*row1[1];

    console.log('after fourth op:');
    console.log(row0);
    console.log(row1);
}

row0[2] = Math.round(row0[2]).toFixed(4);
row1[2] = Math.round(row1[2]).toFixed(4);

document.getElementById("result").innerHTML = (`x0 = ${row0[2]} & x1 = ${row1[2]}`);
return 0;
}

function fixer(){
    solve();
    return false;
}