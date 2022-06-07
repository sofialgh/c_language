import React from 'react'
import PokedexScreen from './PokedexScreen'
import PokemonForm from './PokemonForm'
import './styles/pokedex.css'
import React, { useState, useEffect } from 'react'


function Pokedex(){
    const[ error, setError ] = useState(false)
    const[ loading,setLoading ] = useState(true)
    const [ pokemon, setPokemon ] = useState(null)
    const RandomId = Math.floor(Math.random() *806 + 1)
    const [ pokemonId, setPokemonId ] = useState(RandomId)

    useEffect(() => {
        fetch('https://pokeapi.co/api/v2/pokemon/${pokemonId}\n')
            .then(res => res.json())
            .then(data => {
                setPokemon(data)
                setLoading(false)
                setError(false)
            })
            .catch(err=> {
                setLoading(false)
                setError(true)
            })
    },[])

    return (
        <div className="pokedex">
            <div className="pokedex-left">
                <div className="pokedex-left-top">
                    <div className='light is-sky is-big'/>
                    <div className="light is-red" />
                    <div className="light is-yellow" />
                    <div className="light is-green" />
                </div>
                <div className="pokedex-screen-container">
                    <PokedexScreen
                        pokemon={pokemon}
                        loading={loading}
                        error={error}
                    />
                </div>
                <div className="pokedex-left-bottom">
                    <div className="pokedex-left-bottom-lights">
                        <div className="light is-blue is-medium" />
                        <div className="light is-green is-large" />
                        <div className="light is-orange is-large" />
                    </div>
                    <PokemonForm />
                </div>
            </div>
            <div className="pokedex-right-front" />
            <div className="pokedex-right-back" />
        </div>
    )
}

export default Pokedex