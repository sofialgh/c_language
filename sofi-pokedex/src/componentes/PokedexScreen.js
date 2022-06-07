import React from 'react'
import Stat from './Stat.js'
import ErrorPokemon from '../img/error.gif'
import LoadingPokemon from '../img/loading.gif'

<div className ="pokedex-screen">
    < img
        src = {ErrorPokemon}
        alt = "Hubo un error buscando tu pokemon"
        className="pokedex-no-screen"
    />
</div>

function PokedexScreen({ pokemon, loading, error}){
        return(
            <div className={"pokedex-screen"}>
                    <div className={"pokemon-info"}>
                            <h2 className={"pokemon-name"}>{pokemon.name}</h2>
                          <img
                              className={"pokemon-img"}
                              src={pokemon.sprites.front-default}
                              alt={pokemon.name}
                          />
                            <ul className={pokemon-stats}>
                                {pokemon.stats.map(item=> (<Stat key={item.stat.name} item={item}/>
                                    ))}
                            </ul>
                    </div>

            </div>
        )
}
export default PokedexScreen