def AutoNumR(w):
    state = "q0"
    pila = ['Z0']

    for i in w:
        if state == "q0":
            if i.isalpha() or i == "_":
                state = "q1"
                pila.append("W")
            else:
                state = "M"
        elif state == "q1": 
            if i.isdigit() or i.isalpha() or i == "_":
                state = "q1"
            elif i == "=":
                state = "q2"
                pila.append("W")
            else:
                state = "M"    
        elif state == "q2":
            if i.isdigit():
                state = "q8"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i.isalpha() or i == "_":
                state = "q3"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == "+" or i == "-":
                state = "q4"
            elif i == "(":
                state = "q5"
                pila.append("Y")
            else:
                state = "M"
        elif state == "q3":
            if i.isdigit() or i.isalpha() or i == "_":
                state = "q3"
            elif i == "+" or i == "-" or i == "/" or i == "*" or i == "%":
                state = "q11"
                pila.append("X")
            elif i == ";":
                state = "q15"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == ")":
                state = "q3"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"  
        elif state == "q4":
            if i.isalpha():
                state = "q3"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i.isdigit():
                state = "q9"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == "(":
                state = "q5"
                pila.append("Y")
            else:
                state = "M"
        elif state == "q5":
            if i.isdigit():
                state = "q10"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == "+" or i =="-":
                state = "q7"
            elif i.isalpha() or i == "_":
                state = "q6"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == "(":
                state = "q5"
                pila.append("Y")
            else:
                state = "M"
        elif state == "q6":
            if i.isdigit() or i.isalpha() or i == "_":
                state = "q6"
            elif i == "+" or i == "-" or i == "/" or i == "*" or i == "%":
                state = "q12"
                pila.append("Y")
            elif i == ")":
                state = "q13"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"
        elif state == "q7":
            if i.isalpha() or i == "_":
                state = "q6"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i.isdigit():
                state = "q10"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"
        elif state == "q8":
            if i.isdigit():
                state = "q8"
            elif i == "+" or i == "-" or i == "/" or i == "*" or i == "%":
                state = "q11"
                pila.append("X")
            elif i == ")":
                state = "q8"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == ";":
                state = "q15"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"
        elif state == "q9":
            if i.isdigit():
                state = "q9"
            elif i == "+" or i == "-" or i == "/" or i == "*" or i == "%":
                state = "q11"
                pila.append("X")
            elif i == ";":
                state = "q15"
                pila.pop()
                if len(pila) == 0:
                    return False
            else: 
                state = "M"
        elif state == "q10":
            if i.isdigit():
                state = "q10"
            elif i == "+" or i == "-" or i == "/" or i == "*" or i == "%":
                state = "q12"
                pila.append("Y")
            elif i == ")":
                state = "q13"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"
        elif state == "q11":
            if i.isdigit():
                state = "q8"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i.isalpha() or i == "_":
                state = "q3"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == "(":
                state = "q5"
                pila.append("Y")
            else:
                state = "M"
        elif state == "q12":
            if i.isalpha() or i == "_":
                state = "q6"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i.isdigit():
                state = "q10"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"
        elif state == "q13":
            if i == "+" or i == "-" or i == "/" or i == "*" or i == "%":
                state = "q14"
                pila.append("W")
            elif i == ";":
                state = "q15"
                pila.pop()
                if len(pila) == 0:
                    return False
            else:
                state = "M"
        elif state == "q14":
            if i.isdigit():
                state = "q8"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i.isalpha() or i == "_":
                state = "q3"
                pila.pop()
                if len(pila) == 0:
                    return False
            elif i == "(":
                state = "q5"
                pila.append("Y")
            else:
                state = "M"

    print("\nSu pila es: ", pila)
    print("El tope de su pila es: ", pila[-1])
    print("")

    if(len(pila)!=1):
        return False
    if state == "q15":
        return True
    else: 
        return False

flag=True
while flag:
    # GRAMATICA PARA ESTE AUTOMATA:
    # G = {∑p, ∑n, S, P}
    # ∑t = {=,+,-,*,/,%,(,),0-9,A-Z,a-z}
    # ∑n = {E, ID}
    # P ={
    # E -> ID|E=E|E+E|E-E|E*E|E/E|E%E|(E)|E_E|
    # ID -> A-Z|a-z|0-9|IDA-Z|IDa-z|ID0-9|} 
    
    NumR = input("Ingrese una expresion de Lenguaje C: ")
    if AutoNumR(NumR):
        print("Cadena Aceptada\n")
    else:
        print("Cadena NO Aceptada\n")

    flag=False

