// ==UserScript==
// @name         Clientes Schengen IPHONE
// @namespace    https://www.onlinemictest.com
// @version      0.6
// @description  Seleciona cliente para preenchimento automático no site VFS Global.
// @match        https://visa.vfsglobal.com/*
// @grant        unsafeWindow
// @run-at       document-start
// ==/UserScript==

(function () {
    'use strict';

    // Lista de clientes
    const clientes = [
        {
            nome: "diquenga",
            sobrenome: "manuel",
            nascimento: "06/01/1952",
            passaporte: "N3516008",
            validadePassaporte: "26/11/2039",
            cep: "244",
            telefone: "943498623",
            email: "vfsnew54@outlook.com"
        },
        {
            nome: "kenia",
            sobrenome: "luis",
            nascimento: "20/05/2005",
            passaporte: "N3414975",
            validadePassaporte: "28/08/2034",
            cep: "244",
            telefone: "948761123",
            email: "vfsnew53@outlook.com"
        },
        {
            nome: "vanda",
            sobrenome: "sapalo",
            nascimento: "26/11/2001",
            passaporte: "N3336830",
            validadePassaporte: "27/06/2034",
            cep: "244",
            telefone: "948764723",
            email: "vfsnew56@outlook.com"
        }
        // Adicione mais clientes conforme necessário
    ];

    // Cria o botão de seleção no topo
    const container = document.createElement("div");
    container.style.position = "fixed";
    container.style.display = "flex";
    container.style.top = "60px";
    container.style.left = "50%";
    container.style.transform = "translateX(-50%)";
    container.style.zIndex = "9999";
    container.style.backgroundColor = "transparent";
    container.style.border = "none";

    const select = document.createElement("select");
    select.style.padding = "8px";
    select.style.width = "100px";
    select.style.border = "1px solid #ccc";
    select.style.borderRadius = "6px";
    select.style.backgroundColor = "#f9f9f9";
    select.style.fontSize = "14px";
    select.style.fontWeight = "500";
    select.style.color = "#333";
    select.style.boxShadow = "0 2px 4px rgba(0,0,0,0.1)";
    select.style.outline = "none";
    select.style.transition = "border 0.3s, box-shadow 0.3s";
    select.onfocus = () => {
        select.style.border = "1px solid #007bff";
        select.style.boxShadow = "0 0 5px rgba(0,123,255,0.5)";
    };
    select.onblur = () => {
        select.style.border = "1px solid #ccc";
        select.style.boxShadow = "0 2px 4px rgba(0,0,0,0.1)";
    };

    const defaultOption = document.createElement("option");
    defaultOption.text = "Schengen";
    defaultOption.disabled = true;
    defaultOption.selected = true;
    select.appendChild(defaultOption);

    clientes.forEach((cliente, index) => {
        const option = document.createElement("option");
        option.value = index;
        option.textContent = cliente.nome + " " + cliente.sobrenome;
        select.appendChild(option);
    });

    select.addEventListener("change", function () {
        const c = clientes[this.value];
        preencherCampos(c);
    });

    container.appendChild(select);
    document.body.appendChild(container);

    function preencherCampos(c) {
      const campos = [
          { seletor: '[placeholder="Enter your first name"]', valor: c.nome },
          { seletor: '[placeholder="Please enter last name."]', valor: c.sobrenome },
          { seletor: '[placeholder="Enter passport number"]', valor: c.passaporte },
          { seletor: '[placeholder="44"]', valor: c.cep },
          { seletor: '[placeholder="012345648382"]', valor: c.telefone },
          { seletor: '[placeholder="Enter Email Address"]', valor: c.email },
          { seletor: '#dateOfBirth', valor: c.nascimento },
          { seletor: '#passportExpirtyDate', valor: c.validadePassaporte }
      ];

      campos.forEach(({ seletor, valor }) => {
          const el = document.querySelector(seletor);
          if (el) {
              el.value = valor;
              el.dispatchEvent(new Event("input", { bubbles: true }));
          } else {
              console.warn(`Campo não encontrado para seletor: ${seletor}`);
          }
      });
  }
})();
