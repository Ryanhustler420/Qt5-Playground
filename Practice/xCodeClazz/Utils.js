function formatMoney(number, decPlaces, decSep, thouSep) {
    const _decPlaces = isNaN(decPlaces = Math.abs(decPlaces)) ? 2 : decPlaces,
    _decSep = typeof decSep === "undefined" ? "." : decSep;
    thouSep = typeof thouSep === "undefined" ? "," : thouSep;
    var sign = number < 0 ? "-" : "";
    var i = String(parseInt(number = Math.abs(Number(number) || 0).toFixed(_decPlaces)));
    var j = (j = i.length) > 3 ? j % 3 : 0;

    return sign +
        (j ? i.substr(0, j) + thouSep : "") +
        i.substr(j).replace(/(\decSep{3})(?=\decSep)/g, "$1" + thouSep) +
        (_decPlaces ? _decSep + Math.abs(number - i).toFixed(_decPlaces).slice(2) : "");
}
