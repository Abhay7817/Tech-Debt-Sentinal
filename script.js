//import Chart from 'chart.js/auto';

//const { plugins, Legend } = require("chart.js");
console.log("JS Loaded");
/* global Chart */
const ctx1 = document.getElementById('doughnut').getContext('2d');
const ctx2 = document.getElementById('line_chart').getContext('2d');
fetch('../backend/tech_debt/tech_debt/parse_data.json').then(function (response) {
    if (response.ok == true) {
        return response.json();
    } else {
        console.error("Error response:", response.status);
    }
}).then(function (data) {
    //console.log(data);
    const scores = data.scores;
    const { total, ...filteredScores } = scores;
    //console.log(filteredScores);
    const labels = Object.keys(filteredScores);
    const values = Object.values(filteredScores);
    const list = data.sorted_high;
    //console.log(list);
    const listL = data.month_score;
    const labelsL = listL.map(obj=>Object.keys(obj)[0]);
    //console.log(labelsL);
    const valuesL = listL.map(obj=>Object.values(obj)[0]);
    //console.log(valuesL);
    const names = data.recent_files;
    console.log(names);
    displayctx1(labels, values);
    file_cards(list);
    displayctx2(labelsL, valuesL);
    scanned(names);
});
const dcolors = ["#ff0000", "#33cc33", "#ffff00"];
function displayctx1(labels, values) {
    new Chart(ctx1, {
        type: "doughnut",
        data: {
            labels: labels,
            datasets: [{
                label: 'Scores',
                data: values,
                backgroundColor: dcolors,
                borderColor: 'rgb(255, 102, 0)'
            }]
        },
        options: {
            cutout: '50%',
            radius: '100%',
            rotation: -90,
            circumference: 180,
            animation: {
                animateRotate: true,
                animateScale: false
            },
            plugins:{
                legend:{
                    labels:{
                        color: 'white'
                    }
                }
            },
            responsive: true,
            maintainAspectratio: true
        }
    });
}
//console.log("NEW CODE LOADED");
const cardcontainer = document.getElementById('cardcontainer');
function file_cards(list) {
    cardcontainer.innerHTML = '';
    list.forEach(element => {
        for (let val in element) {
            const card = document.createElement('div');
            card.classList.add('cards');
            card.textContent = "Filename: " + val + "\u00A0\u00A0\u00A0\u00A0\u00A0\u00A0\u00A0\u00A0High score: " + element[val];
            card.style.fontFamily = "Arial, Helvetica, sans-serif";
            card.style.color = 'rgb(255, 255, 255)';
            //console.log(card);
            //console.log(val, element[val]);
            card.style.border = '2px solid';
            card.style.borderRadius = '5px';
            card.style.borderColor = 'rgb(255, 102, 0)';
            card.style.margin = '10px';
            card.style.padding = '10px';
            card.style.backgroundColor = 'rgb(134, 134, 134, 0.5)';
            cardcontainer.appendChild(card);
        }
    });
}
function displayctx2(labelsL, valuesL){
    //ctx2.canvas.style.backgroundColor = 'rgba(0, 255, 255, 0.2)';
    new Chart(ctx2,{
        type: 'line',
        data:{
            labels: labelsL,
            datasets:[{
                label: 'Score Trend',
                data: valuesL,
                fill: true,
                borderColor: 'rgb(255, 102, 0)',
                tension: 0.1
            }]
        },
        options:{
            plugins:{
                legend:{
                    labels:{
                        color:'white'
                    }
                }
            },
            scales:{
                x:{
                    ticks:{
                        color: 'white'
                    },
                    title:{
                        display: true,
                        text: 'Months',
                        color: 'white'
                    },
                    grid:{
                        color: 'rgba(255, 255, 255, 0.5)'
                    }
                },
                y:{
                    ticks:{
                        color: 'white'
                    },
                    title:{
                        display: true,
                        text: 'Score',
                        color: 'white'
                    },
                    grid:{
                        color: 'rgba(255, 255, 255, 0.5)'
                    }
                }
            },
            responsive: true,
            maintainAspectratio: true
        }
    });
}
const blokcontainer = document.getElementById('blokcontainer');
function scanned(names){
    blokcontainer.innerHTML = '';
    names.forEach(name=>{
        const blok = document.createElement('div');
        blok.classList.add('blocks');
        blok.textContent = name;
        blok.style.fontFamily = "Arial, Helvetica, sans-serif";
        blok.style.color = 'rgb(255, 255, 255)';
        blok.style.border = '2px solid';
        blok.style.borderRadius = '5px';
        blok.style.borderColor = 'rgb(255, 102, 0)';
        blok.style.margin = '10px';
        blok.style.padding = '10px';
        blok.style.backgroundColor = 'rgb(134, 134, 134, 0.5)';
        blokcontainer.appendChild(blok);
    });
}