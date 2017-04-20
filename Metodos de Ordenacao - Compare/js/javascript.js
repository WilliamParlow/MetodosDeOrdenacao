var options = {
  responsive:true,
  legend: {
    display: true,
    labels: {
      fontColor: 'rgb(0, 0, 0)'
    }
  }
};

var text1 = ["Comparacoes", "Trocas" ,"Tempos"];
var data = [];
var obj = [];

for(var i = 0 ; i<6;i++){

  text1.forEach(function(text) {
    if(i===5){
      data = data.concat(geraGraficoCompleto(text));
    }else{
      data = data.concat(geraGraficoUnico(i,text));
    }
  });

}

window.onload = function(){
  var texto ="";
  var i=0;
  for(i=1;i<=18;i++){
    texto = "Grafico"+i;
    ctx = document.getElementById(texto).getContext('2d');
    var myChart = new Chart(ctx,data[i-1]);
  }

  /*

  let charts = document.querySelectorAll("canvas");

  charts.forEach(function(chartAtual) {
  chartAtual.classList.add('tamanho');
});
*/

}

function geraGraficoUnico(i,text) {
  obj= {
    type: 'line',
    data: {
      labels: ["10000 numeros ordenados", "10000 numeros invertidos", "10000 numeros aleatorios"],
      datasets: [{
        label: text,
        data: dadosGerais[i][text],
        backgroundColor: "rgba(255,220,21, .5)"
      }]
    }
  };
  return obj;
}

function geraGraficoCompleto(text){
  obj= {
    type: 'line',
    data: {
      labels: ["10000 numeros ordenados", "10000 numeros invertidos", "10000 numeros aleatorios"],
      datasets: [{
        label: "Bubble",
        data: dadosGerais[0][text],
        backgroundColor: "rgba(50,0,0,0.2)"
      }, {
        label: "Insertion",
        data: dadosGerais[1][text],
        backgroundColor: "rgba(100,255,100,0.2)"
      }, {
        label: "Selection",
        data: dadosGerais[2][text],
        backgroundColor: "rgba(100,100,255,0.2)"
      }, {
        label: "Merge",
        data: dadosGerais[3][text],
        backgroundColor: "rgba(153,255,51,0.2)"
      }, {
        label: "Quick",
        data: dadosGerais[4][text],
        backgroundColor: "rgba(255,255,51,0.2)"
      }]
    }
  };
  return obj;
}
