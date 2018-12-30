// Learn more about F# at http://fsharp.org
// See the 'F# Tutorial' project for more help.
exception InnerError of string
exception OuterError of string
[<EntryPoint>]
let main argv = 
    let testFonction = "test"
    let monInt = 4
    let monFloat = 1.001f
    let monDouble = 1.2232
    let monChar = 'a'
    let monBool = true

    let meInt monInte : int = 
        let monIntM = 2
        monInte * monIntM

    let monResult = meInt monInt

    printfn "test de print"
    printfn "%s" testFonction
    printfn "%i" monInt
    printfn "%i" monResult
    printfn "%f" monFloat
    printfn "%f" monDouble
    printfn "%c" monChar
    printfn "%b" monBool
    printfn "%A" argv

    let list3 = [1 .. 10]
    let list4 = ['a' .. 'z']
    printfn "The list: %A" list3
    printfn "The list: %A" list4

    let maFonctionSomme liste : int =
        List.sum liste
    
    let maSuperSomme = maFonctionSomme list3

    printfn "%i" maSuperSomme

 

    let function1 x y =
        try
            try
                if x = y then raise (InnerError("inner"))
                else raise (OuterError("outer"))
            with
               InnerError(str) -> printfn "Error1 %s" str
        with
            OuterError(str) -> printfn "Error2 %s" str

    function1 (meInt 2) (meInt 2)
    function1 (meInt 3) 2

    0 // return an integer exit code