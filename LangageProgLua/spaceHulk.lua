--Fonctions

function fight()
	round = 0

	gabriel = coroutine.wrap(spaceMarineFC)
	xenos = coroutine.wrap(genestealer)

    gabriel()
    xenos()

    io.write("\n")

	while not endCombat do
		
		io.write("Phase "..round.."\n")
		io.write("\nDeplacement\n")
		gabriel()
		io.write("\n")
		xenos()
		io.write("\nRecherche\n")
		gabriel()
		xenos()
		io.write("\nDecision\n")
		gabriel()
		xenos()
		io.write("\nComplexAction\n")
		gabriel()
		xenos()
		round = round+1

		io.write("\n")
	end

	if(spaceMarine.pv<=0 and tyranide.pv<=0) then
		io.write("C'est un massacre, personne n'a survecu\n")
	elseif(spaceMarine.pv<=0 and tyranide.pv>0)then
		io.write("Et c'est aisni que débuta le massacre de Maccragh et de tous ses habitants\n")
	elseif(spaceMarine.pv>0 and tyranide.pv<=0)then
		io.write("L'éradication des xénos est complète, que l'empereur nous garde, gloire à l'Imperium\n")
	else
		io.write("Vous avez entrer dans le warp, vous n'êtes pas supposez être ici si aucun d'entre vous n'est mort\n")
	end
end

function spaceMarineFC()
	deplacement1 = coroutine.wrap(deplacement)
	recherche1 = coroutine.wrap(recherche)
	decision1 = coroutine.wrap(decision)

	io.write("FOR THE EMPEROR!!!!!!\n")
	coroutine.yield()
	while true do
		currentPlayer = 'SM'
		deplacement1()
		coroutine.yield()
		currentPlayer = 'SM'
		recherche1()
		coroutine.yield()
		currentPlayer = 'SM'
		decision1()
		coroutine.yield()
		currentPlayer = 'SM'
		decision1()
		coroutine.yield()
	end
end

function genestealer()
	deplacement2 = coroutine.wrap(deplacement)
	recherche2 = coroutine.wrap(recherche)
	decision2 = coroutine.wrap(decision)
	
	io.write("Kreeeuyyyorkruuuuikksssss\n")
	coroutine.yield()
	while(true) do
		currentPlayer = 'G'
		deplacement2()
		coroutine.yield()
		currentPlayer = 'G'
		recherche2()
		coroutine.yield()
		currentPlayer = 'G'
		decision2()
		coroutine.yield()
		currentPlayer = 'G'
		decision2()
		coroutine.yield()

	end
end

function deplacement()
	local direction = 0
	math.randomseed(os.time())
	while(true) do
		if(enCombat)then
			coroutine.yield()
			break
		end
		direction = math.random(1,4)
		io.write("Position de départ\n")
		if currentPlayer == 'SM' then
			io.write(spaceMarine.nom.." : "..spaceMarine.posX.." "..spaceMarine.posY.."\n")
			if(direction==1--[[Nord]]) then
				spaceMarine.posY = spaceMarine.posY-spaceMarine.mouv
				io.write("Deplacement de "..spaceMarine.mouv.." vers le nord\n")
				if(spaceMarine.posY<0) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posY=0
				end

			elseif(direction==2--[[Est]]) then
				spaceMarine.posX = spaceMarine.posX+spaceMarine.mouv
				io.write("Deplacement de "..spaceMarine.mouv.." vers l'est\n")
				if(spaceMarine.posX>maxTabX) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posX=maxTabX
				end
			elseif(direction==3--[[Sud]]) then
				spaceMarine.posY = spaceMarine.posY+spaceMarine.mouv
				io.write("Deplacement de "..spaceMarine.mouv.." vers le sud\n")
				if(spaceMarine.posY>maxTabY) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posY=maxTabY
				end
			else--[[Ouest]] 
				spaceMarine.posX = spaceMarine.posX-spaceMarine.mouv
				io.write("Deplacement de "..spaceMarine.mouv.." vers l'ouest\n")
				if(spaceMarine.posX<0) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posX=0
				end
			end
			io.write("Position finale\n")
			io.write(spaceMarine.nom.." : "..spaceMarine.posX.." "..spaceMarine.posY.."\n")
	    elseif currentPlayer == 'G' then
	    	io.write(tyranide.nom.." : "..tyranide.posX.." "..tyranide.posY.."\n")
	    	if(direction==1--[[Nord]]) then
				tyranide.posY = tyranide.posY-tyranide.mouv
				io.write("Deplacement de "..tyranide.mouv.." vers le nord\n")
				if(tyranide.posY<0) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posY=0
				end
			elseif(direction==2--[[Est]]) then
				tyranide.posX = tyranide.posX+tyranide.mouv
				io.write("Deplacement de "..tyranide.mouv.." vers l'est\n")
				if(tyranide.posX>maxTabX) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posX=maxTabX
				end
			elseif(direction==3--[[Sud]]) then
				tyranide.posY = tyranide.posY+tyranide.mouv
				io.write("Deplacement de "..tyranide.mouv.." vers le sud\n")
				if(tyranide.posY>maxTabY) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posY=maxTabY
				end
			else--[[Ouest]] 
				tyranide.posX = tyranide.posX-tyranide.mouv
				io.write("Deplacement de "..tyranide.mouv.." vers l'ouest\n")
				if(tyranide.posX<0) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posX=0
				end
			end
			io.write("Position finale\n")
			io.write(tyranide.nom.." : "..tyranide.posX.." "..tyranide.posY.."\n")
	    end
		coroutine.yield()
	end
end

function recherche()
	while(true) do
		if currentPlayer == 'SM' then
			spaceMarine.inSight=true
			spaceMarine.inRange=false
			if (tyranide.posX<=spaceMarine.posX) and (tyranide.posX>=(spaceMarine.posX-spaceMarine.vision)) and (tyranide.posY==spaceMarine.posY) then
				if(tyranide.posX>=(spaceMarine.posX-spaceMarine.portee))then
					spaceMarine.inRange = true
				end
				io.write("Enemi repere\n")
			elseif (tyranide.posX>=spaceMarine.posX) and (tyranide.posX<=(spaceMarine.posX+spaceMarine.vision)) and (tyranide.posY==spaceMarine.posY) then
				if(tyranide.posX<=(spaceMarine.posX+spaceMarine.portee))then
					spaceMarine.inRange = true
				end
				io.write("Enemi repere\n")
			elseif (tyranide.posY<=spaceMarine.posY) and (tyranide.posY>=(spaceMarine.posY-spaceMarine.vision)) and (tyranide.posX==spaceMarine.posX) then
				if(tyranide.posY>=(spaceMarine.posY-spaceMarine.portee))then
					spaceMarine.inRange = true
				end
				io.write("Enemi repere\n")
			elseif (tyranide.posY>=spaceMarine.posY) and (tyranide.posY<=(spaceMarine.posY+spaceMarine.vision)) and (tyranide.posX==spaceMarine.posX) then
				if(tyranide.posY<=(spaceMarine.posY+spaceMarine.portee))then
					spaceMarine.inRange = true
				end
				io.write("Enemi repere\n")
			else
				io.write("RAS\n")
				spaceMarine.inSight=false
			end
	    elseif currentPlayer == 'G' then
	    	tyranide.inSight=true
	    	tyranide.inRange=false
	    	if (spaceMarine.posX<=tyranide.posX) and (spaceMarine.posX>=(tyranide.posX-tyranide.vision)) and (spaceMarine.posY==tyranide.posY) then
	    		if(spaceMarine.posX>=(tyranide.posX-tyranide.portee))then
					tyranide.inRange = true
				end
				io.write("I've found my prey\n")
			elseif (spaceMarine.posX>=tyranide.posX) and (spaceMarine.posX<=(tyranide.posX+tyranide.vision)) and (spaceMarine.posY==tyranide.posY) then
				if(spaceMarine.posX<=(tyranide.posX+tyranide.portee))then
					tyranide.inRange = true
				end
				io.write("I've found my prey\n")
			elseif (spaceMarine.posY<=tyranide.posY) and (spaceMarine.posY>=(tyranide.posY-tyranide.vision)) and (spaceMarine.posX==tyranide.posX) then
				if(spaceMarine.posY>=(tyranide.posY-tyranide.portee))then
					tyranide.inRange = true
				end
				io.write("I've found my prey\n")
			elseif (spaceMarine.posY>=tyranide.posY) and (spaceMarine.posY<=(tyranide.posY+tyranide.vision)) and (spaceMarine.posX==tyranide.posX) then
				if(spaceMarine.posY<=(tyranide.posY+tyranide.portee))then
					tyranide.inRange = true
				end
				io.write("I've found my prey\n")
			else
				io.write("My hunger grows\n")
				tyranide.inSight=false
			end
	    end
		coroutine.yield()
	end
end


function courrir()
	local direction = 0
	math.randomseed(os.time())
	while(true) do
		if(enCombat)then
			coroutine.yield()
			break
		end
		direction = math.random(1,4)
		io.write("Position de départ\n")
		if currentPlayer == 'SM' then
			io.write(spaceMarine.nom.." : "..spaceMarine.posX.." "..spaceMarine.posY.."\n")
			if(direction==1--[[Nord]]) then
				spaceMarine.posY = spaceMarine.posY-spaceMarine.sprint
				io.write("Deplacement de "..spaceMarine.mouv.." vers le nord\n")
				if(spaceMarine.posY<0) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posY=0
				end

			elseif(direction==2--[[Est]]) then
				spaceMarine.posX = spaceMarine.posX+spaceMarine.sprint
				io.write("Deplacement de "..spaceMarine.mouv.." vers l'est\n")
				if(spaceMarine.posX>maxTabX) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posX=maxTabX
				end
			elseif(direction==3--[[Sud]]) then
				spaceMarine.posY = spaceMarine.posY+spaceMarine.sprint
				io.write("Deplacement de "..spaceMarine.mouv.." vers le sud\n")
				if(spaceMarine.posY>maxTabY) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posY=maxTabY
				end
			else--[[Ouest]] 
				spaceMarine.posX = spaceMarine.posX-spaceMarine.sprint
				io.write("Deplacement de "..spaceMarine.mouv.." vers l'ouest\n")
				if(spaceMarine.posX<0) then
					io.write("AREA NOT CHARGED\n")
					spaceMarine.posX=0
				end
			end
			io.write("Position finale\n")
			io.write(spaceMarine.nom.." : "..spaceMarine.posX.." "..spaceMarine.posY.."\n")
	    elseif currentPlayer == 'G' then
	    	io.write(tyranide.nom.." : "..tyranide.posX.." "..tyranide.posY.."\n")
	    	if(direction==1--[[Nord]]) then
				tyranide.posY = tyranide.posY-tyranide.sprint
				io.write("Deplacement de "..tyranide.mouv.." vers le nord\n")
				if(tyranide.posY<0) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posY=0
				end
			elseif(direction==2--[[Est]]) then
				tyranide.posX = tyranide.posX+tyranide.sprint
				io.write("Deplacement de "..tyranide.mouv.." vers l'est\n")
				if(tyranide.posX>maxTabX) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posX=maxTabX
				end
			elseif(direction==3--[[Sud]]) then
				tyranide.posY = tyranide.posY+tyranide.sprint
				io.write("Deplacement de "..tyranide.mouv.." vers le sud\n")
				if(tyranide.posY>maxTabY) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posY=maxTabY
				end
			else--[[Ouest]] 
				tyranide.posX = tyranide.posX-tyranide.sprint
				io.write("Deplacement de "..tyranide.mouv.." vers l'ouest\n")
				if(tyranide.posX<0) then
					io.write("AREA NOT CHARGED\n")
					tyranide.posX=0
				end
			end
			io.write("Position finale\n")
			io.write(tyranide.nom.." : "..tyranide.posX.." "..tyranide.posY.."\n")
	    end
		coroutine.yield()
	end
end

function decision()
	pireCopierCollerDeLUniversCourrir = coroutine.wrap(courrir)
	while(true) do
		if currentPlayer == 'SM' then
			if(spaceMarine.posX==tyranide.posX and spaceMarine.posY==tyranide.posY) then
				io.write(currentPlayer.."-> Combattre\n")
				coroutine.yield()
				enCombat = true
				io.write("Attaque du "..spaceMarine.titre.." "..spaceMarine.nom.."\n")
				io.write("Un coup d'eppee tronconeuse en pleine tronche pour le xenos  ("..(spaceMarine.dmgC+100).." dégat)\n")--Ce qui devrait normalement etre
				tyranide.pv = tyranide.pv-spaceMarine.dmgC
		    elseif(spaceMarine.inRange)then
		    	io.write(currentPlayer.."-> Tirer\n")
		    	coroutine.yield()
		    	io.write("Tir du "..spaceMarine.titre.." "..spaceMarine.nom.."\n")
				io.write("Tir de bolter vers l'enemi ("..(spaceMarine.dmgT+100).." dégat)\n")--Ce qui devrait normalement etre
				tyranide.pv = tyranide.pv-spaceMarine.dmgT
		    	io.write("")
		    else
		    	io.write(currentPlayer.."-> Courrir\n")
		    	coroutine.yield()
		    	currentPlayer = 'SM'
		    	pireCopierCollerDeLUniversCourrir()
		    end
	    elseif currentPlayer == 'G' then--Ici meme si le space marine a bouger on consided qu'ils en meme temps et que le xenos le tape en passant
	    	if(spaceMarine.posX==tyranide.posX and spaceMarine.posY==tyranide.posY) then
				io.write(currentPlayer.."-> Combattre\n")
				coroutine.yield()
				enCombat = true
		    	io.write("Attaque du "..tyranide.nom.."\n")
		    	io.write("Le xenos attaque ferocement  ("..tyranide.dmgC.." dégat)\n")--Ce qui devrait normalement etre
				spaceMarine.pv = spaceMarine.pv-tyranide.dmgC
		    elseif(tyranide.inRange)then
		    	io.write(currentPlayer.."-> Tirer\n")
		    	coroutine.yield()
		    	io.write("Tir du "..tyranide.nom.."\n")
				io.write("Le xenos envoit des tirs de biomasse ("..tyranide.dmgT.." dégat)\n")--Ce qui devrait normalement etre
				spaceMarine.pv = spaceMarine.pv-tyranide.dmgT
		    	io.write("")
		    else
		    	io.write(currentPlayer.."-> Courrir\n")
		    	coroutine.yield()
		    	currentPlayer = 'G'
		    	pireCopierCollerDeLUniversCourrir()
		 		
		    end

	    end

	    if (spaceMarine.pv<=0 or tyranide.pv<=0) then
					endCombat = true
		end
				
		coroutine.yield()
	end
end
--Variables Globales
fichier = io.open ("combat.txt", "w")
io.output(fichier)
enCombat = false
endCombat=false

--Tableau
maxTabX = 20
maxTabY = 20
--Space Marine
spaceMarine = {titre,nom,posX,posY,pv,vision,mouv,portee,dmgT,dmgC,sprint,inSight,inRange}
spaceMarine.titre = "Capitaine"
spaceMarine.nom = "Gabriel Angelos"
spaceMarine.posX = 0
spaceMarine.posY = 0
spaceMarine.pv = 3
spaceMarine.mouv = 2
spaceMarine.vision = 4
spaceMarine.portee = 4
spaceMarine.dmgT = 2
spaceMarine.dmgC = 1
spaceMarine.sprint = 1
spaceMarine.inSight = false
spaceMarine.inRange = false

--Genestealer
tyranide = {nom,posX,posY,pv,vision,mouv,portee,dmgT,dmgC,sprint,inSight,inRange}
tyranide.nom = "Genestealer"
tyranide.posX = 19
tyranide.posY = 19
tyranide.pv = 5
tyranide.mouv = 3
tyranide.vision = 6
tyranide.portee = 1
tyranide.dmgT = 1
tyranide.dmgC = 2
tyranide.sprint = 2
tyranide.inSight = false
tyranide.inRange = false

currentPlayer = "null"
--execution
game = coroutine.create(fight)
coroutine.resume(game)

io.close(fichier)