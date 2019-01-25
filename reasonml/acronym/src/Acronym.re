let abbreviate = (str) => {
    let regex = [%re "/[ -]/"];
    let arr = Js.String.splitByRe(regex, str);
    let f = (item) => { String.capitalize(String.sub(item, 0, 1)) };
    let initials = ArrayLabels.map(f, arr);
    Js.Array.joinWith("", initials)
};
