var contadora = 1;

function next() {

  let canvas = document.querySelector(`#Grafico${contadora}`);
  fadeOut(canvas);

  contadora++

  if (contadora > 18) {
    contadora = 1;
  }

  canvas = document.querySelector(`#Grafico${contadora}`);
  fadeIn(canvas);

  let title = document.querySelector('#ordenacao');
  title.textContent = canvas.dataset.ordenacao;

}

function prev() {

  let canvas = document.querySelector(`#Grafico${contadora}`);
  fadeOut(canvas);

  contadora--;

  if (contadora < 1) {
    contadora = 18;
  }

  canvas = document.querySelector(`#Grafico${contadora}`);
  fadeIn(canvas);

  let title = document.querySelector('#ordenacao');
  title.textContent = canvas.dataset.ordenacao;

}



function fadeIn(canvas) {

    canvas.classList.add('fadeIn');
    canvas.classList.remove('fadeOut');

    setTimeout(function() {
      canvas.classList.remove('hidden');
    }, 500);

}

function fadeOut(canvas) {

  canvas.classList.add('fadeOut');
  canvas.classList.remove('fadeIn');

  setTimeout(function() {
    canvas.classList.add('hidden');
  }, 500);

}
