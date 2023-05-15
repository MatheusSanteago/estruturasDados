fila = {
    dados: [],
    fim: 0,
    inicio: 0
}

function entrar(value){
    if(fila.fim === 5){
        console.log("Fila cheia!")
    } else {
        fila.dados[fila.fim] = value
        fila.fim += 1
    }
}
function sair(){
    if(fila.fim === fila.inicio){
        console.log("Fila vazia!")
    } else {
        for(let i= 0; i < fila.dados.length; i++){
            fila.dados[i] = fila.dados[i+1]
        }
        fila.fim -= 1
    }
}

function verFila(){
    console.log("[");
    console.log(fila.dados[0], fila.dados[1], fila.dados[2], fila.dados[3], fila.dados[4]);
    console.log("]");
}

    var op = parseInt(prompt('Escolha um item no menu'))
    while(op !== 0){
        switch (op) {
            case 1:
                verFila()
                entrar(parseInt(prompt("Digite um valor")))
                break;
            case 2:
                verFila()
                sair()
                break;
            default:
                break;
        }
        op = parseInt(prompt('Escolha um item no menu'))
    }

