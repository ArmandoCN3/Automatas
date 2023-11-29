def AutoNumR(w):
    state = "q0"
    for i in w:
        if state == "q0":
            if i.isdigit() or i=="-" or i=="+":
                state = "q1"
            else:
                state = "M"
        elif state == "q1":
            if i.isdigit():
                state = "q1"
            elif i == ".":
                state = "q2"
            elif i == "E" or i =="e":
                state = "q4"
            else:
                state = "M"
        elif state == "q2":
            if i.isdigit():
                state = "q3"
            else:
                state = "M"
        elif state == "q3":
            if i.isdigit():
                state = "q3"
            elif i == "E" or i=="e":
                state = "q4"
            else:
                state = "M"
        elif state == "q4":
            if i.isdigit():
                state="q3"
            elif i=="-" or i=="+":
                state="q5"
            else:
                state="M"
        elif state == "q5":
            if i.isdigit():
                state="q3"
            else:
                state="M"
    if state == "q1" or state == "q3":
        return True
    else: 
        return False

def AutoBin():
    def transicion (estado,sigma):
        res=delta[(estado,sigma)]
        return res
    Q=['q0','q1','q2','q3','q4','q5','q6','M']
    sigma=['0','1']
    s= 'q0'
    F=['q3','q6']
    delta={
        ('q0','0'):'q1',
        ('q0','1'):'q2',
        ('q1','0'):'q3',
        ('q1','1'):'q5',
        ('q2','0'):'q4',
        ('q2','1'):'M',
        ('q3','0'):'q1',
        ('q3','1'):'q6',
        ('q4','0'):'q3',
        ('q4','1'):'q5',
        ('q5','0'):'q3',
        ('q5','1'):'M',
        ('q6','0'):'q1',
        ('q6','1'):'M'}
        
    estado=s
    w = input("Ingrese una Cadena sobre Σ={0,1}: ")
    for sigma in w:
        estado= transicion(estado,sigma)
    if estado in F:
        print(w,"es aceptada")
    else:
        print(w,"no es aceptada")

def Longitud(): 
    def transicion (estado,sigma):
        res=delta[(estado,sigma)]
        return res
    Q=['q0','q1','q2','q3','q4','q5','q6']
    sigma=['a','b','c','d']
    s= 'q0'
    F=['q5']
    delta={
        ('q0','a'):'q1',
        ('q0','b'):'q2',
        ('q0','c'):'q3',
        ('q0','d'):'q4',
        ('q1','a'):'q5',
        ('q1','b'):'q2',
        ('q1','c'):'q3',
        ('q1','d'):'q4',
        ('q2','a'):'q1',
        ('q2','b'):'q5',
        ('q2','c'):'q3',
        ('q2','d'):'q4',
        ('q3','a'):'q1',
        ('q3','b'):'q2',
        ('q3','c'):'q5',
        ('q3','d'):'q4',
        ('q4','a'):'q1',
        ('q4','b'):'q2',
        ('q4','c'):'q3',
        ('q4','d'):'q5',
        ('q5','a'):'q5',
        ('q5','b'):'q5',
        ('q5','c'):'q5',
        ('q5','d'):'q5',}   
    estado=s
    w = input("Ingrese una Cadena sobre Σ={a,b,c,d}: ")
    for sigma in w:
        estado= transicion(estado,sigma)
    if estado in F:
        print(w,"es aceptada")
    else:
        print(w,"no es aceptada")

flag=True
while flag:

    choice=input("Seleccione una opción:\n"+
    "a) Validar Numeros Reales\n"+
    "b) Validar sobre Σ={0,1}\n"+
    "c) Validar Cadenas sobre Σ={a,b,c,d}\n"+
    "d) Máquina Expendedora\n"+
    "e) Salir\n"+
    ">")

    if choice=="a":
        print("**************Inciso A)***************")
        NumR = input("Ingrese Numero Real: ")
        if AutoNumR(NumR):
            print("Cadena Aceptada")
        else:
            print("Cadena NO Aceptada")
        print("\n")

    elif choice=="b":
        print("**************Inciso B)***************")
        AutoBin()
        print("\n")

    elif choice=="c":
        print("**************Inciso C)***************")
        Longitud()

        print("\n")

    elif choice=="d":
        print("**************Inciso D)***************")  
        print("Maquina Expendora")
        print("La Maquina solo Acepta Monedas de: $0.25 y $1.00")
        print("Para Obtener el producto debe de insertar almenos $1.25")
        select = True
        value = 0.00
        getP = False
        while select:
            print("1) Insertar $0.25\n"+
            "2) Insertar $1.00\n"+
            "3) Seleccionar Producto\n"+
            "4) Salir")
            
            choice = int(input(">"))
            if choice == 1:
                value = value + 0.25
            elif choice == 2:
                value = value + 1.00
            elif choice == 3:
                getP=True
            else:
                select = False

            if value == 0.00:
                print(f"Insertado en Maquina: ${value}")
                getP = False
            elif value == 0.25:
                print(f"Insertado en Maquina: ${value}")
                getP = False
            elif value == 0.50:
                print(f"Insertado en Maquina: ${value}")
                getP = False
            elif value == 0.75:
                print(f"Insertado en Maquina: ${value}")
                getP = False
            elif value == 1.00:
                print(f"Insertado en Maquina: ${value}")
                getP = False
            elif value >= 1.25:
                print(f"Insertado en Maquina: ${value}")
                if getP:
                    print("GRACIAS -> Recoja Su Producto")
                    value = 0.00
                    getP = False
            elif value >= 1.50:
                print(f"Insertado en Maquina: ${value}")
                if getP:
                    print("GRACIAS -> Recoja Su Producto")
                    value = 0.00
                    getP = False
            elif value >= 1.75:
                print(f"Insertado en Maquina: ${value}")
                if getP:
                    print("GRACIAS -> Recoja Su Producto")
                    value = 0.00
                    getP = False
            elif value >= 2.00:
                print(f"Insertado en Maquina: ${value}")
                if getP:
                    print("GRACIAS -> Recoja Su Producto")
                    value = 0.00
                    getP = False
        print("\n")
    else:
        flag = False